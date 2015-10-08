#include "accountcontroller.h"
#include "users.h"


AccountController::AccountController(const AccountController &)
    : ApplicationController()
{ }

void AccountController::users()
{
    updateUser();

    render("users");
}
void AccountController::form()
{
    updateUser();
    if(isUserLoggedIn())
    {
        QString notice = H::tr("already_authenticated");
        tflash(notice);
        redirect(QUrl("/"));
    }
}

void AccountController::login()
{
    form();

    if(httpRequest().hasForm())
    {

        QString username = httpRequest().formItemValue("username");
        QString password = httpRequest().formItemValue("password");

        Users user = Users::authenticate(username, password);

        QString header = H::tr("Sign in"); ;
        texport(header);

        if (!user.isNull()) {

            if(httpRequest().hasFormItem("remember"))
            {
                addCookie("user_id", std::to_string(user.id()).c_str(), QDateTime::currentDateTime().addMonths(3), "/");
                user.setRememberCreatedAt(QDateTime::currentDateTime());
            }
            user.setCurrentSignInAt(QDateTime::currentDateTime());
            user.setCurrentSignInIp(httpRequest().clientAddress().toString());
            user.setSignInCount(user.signInCount() + 1);
            user.update();

            userLogin(&user);

            QString success = H::tr("signed_in");
            tflash(success);

            redirect(QUrl("/"));
        } else {
            QString error = H::tr("Login failed");
            texport(error);
        }
    }
    render("form");
}

void AccountController::logout()
{
    updateUser();

    if(!isUserLoggedIn())
    {
        QString notice = H::tr("not_authenticated_yet");
        tflash(notice);
        redirect(QUrl("/"));
        return;
    }

    Users user = getUser();

    user.setLastSignInAt(user.currentSignInAt());
    user.setLastSignInIp(httpRequest().clientAddress().toString());
    user.update();

    userLogout();

    QString success = H::tr("signed_out");
    tflash(success);

    redirect(QUrl("/"));  // redirect to main page
}


void AccountController::registration()
{
    form();

    if(!httpRequest().hasForm())
    {
        render("register");
        return ;
    }

    QString login = httpRequest().formItemValue("username", "").trimmed();
    QString email = httpRequest().formItemValue("email", "").trimmed();
    QString pass = httpRequest().formItemValue("password", "").trimmed();
    QString pass_confirm = httpRequest().formItemValue("password_confirmation", "").trimmed();

    tflash(login);
    tflash(email);
    tflash(pass);
    tflash(pass_confirm);

    QString error = "";

    if(login.isEmpty())
        error += H::tr("Enter your username") + "<br>";
    if(email.isEmpty())
        error += H::tr("Enter your email") + "<br>";
    if(pass.isEmpty())
        error += H::tr("Enter your password") + "<br>";
    if(pass != pass_confirm)
        error += H::tr("Password and password confirmation are different") + "<br>";

    if(!error.isEmpty())
    {
        showFlash(error, "register");
        return;
    }

    TSqlQuery query;

    query.prepare("SELECT COUNT(1) FROM `users` WHERE `username` = ? OR `email` = ?");
    query.addBind(login).addBind(email);
    query.exec();

    if(!query.next())
    {
        showFlash(H::tr("Database error, sorry.."), "register");
        return ;
    }
    if(query.value(0).toBool())
    {
        showFlash(H::tr("User") + " '" + login + "' " + H::tr("already exists"));
        return ;
    }

    Botan::LibraryInitializer init;
    Botan::AutoSeeded_RNG rng;
    int a = 1;
    QString encrypted = QString::fromStdString(Botan::generate_bcrypt(pass.toStdString(), rng, a));

    Users::create(
        login, email, encrypted,
        "", QDateTime(), QDateTime(),
        0, QDateTime(), QDateTime(),
        httpRequest().clientAddress().toString(), "", "",
        QDateTime(), QDateTime(), "",
        0, "", QDateTime()
    );

    render("register");      // shows form view
}

void AccountController::profile()
{
    if(!isUserLoggedIn())
    {
        showFlash(H::tr("not_authenticated_yet"), QString());
        redirect(QUrl("/"));
        return ;
    }
    showUserProfile(QString::number(getUser().id()));
}

void AccountController::editProfileAvatar(const QString& userId)
{
    const int id = userId.toInt();
    if(httpRequest().method() != Tf::Post || !id)
    {
        showFlash(H::tr("User not found"), "profile");
        return ;
    }

    if(!id || !isUserLoggedIn() || !getUser().isAdmin() || id != getUser().id())
    {
        showFlash(H::tr("User not found"), "profile");
        return ;
    }

    const QString& oldAvatar = httpRequest().formItemValue("old_avatar", "").trimmed();

    TSqlQuery query;
    if(httpRequest().hasFormItem("delete_avatar"))
    {
        query.prepare("UPDATE `profiles` SET `avatar` = NULL WHERE `user_id` = ? LIMIT 1");
        query.addBind(id);
        query.exec();

        if(!oldAvatar.isEmpty())
        {
            QFile file("./public/images/avatars/" + oldAvatar);
            if(file.exists())
                file.remove();
            file.close();
        }
        QString success = H::tr("Profile was successfully updated");
        tflash(success);
        redirect(H::createUrl({"user", "profile"}));
        return ;
    }

    //upload new avatar
    auto &image = httpRequest().multipartFormData();
    //name of input tag
    const auto& inputName = "avatar";

    if(!image.originalFileName(inputName).isEmpty())
    {


        //type of image
        QString imageType = image.contentType(inputName);

        imageType = imageType.mid(imageType.indexOf('/') + 1).toUpper().trimmed().replace("GIF", "PNG");

        const auto& typeRegex = QRegExp("jpe?g|png|gif", Qt::CaseInsensitive);
        const auto& nameRegex = QRegularExpression("(?<=\\.)(?:jpe?g|png|gif)$", QRegularExpression::CaseInsensitiveOption | QRegularExpression::UseUnicodePropertiesOption);

        if(image.isEmpty() || !image.size(inputName))
        {
            redirect(H::createUrl({"user", "profile"}));
            return ;
        }
        //check image & image type
        if( !imageType.contains(typeRegex) || !image.originalFileName(inputName).contains(nameRegex) )
        {
            QString error = H::tr("Wrong image format");
            tflash(error);
            redirect(H::createUrl({"user", "profile"}));
            return ;
        }

        const QString& newImageName = H::imageResize(image.entity(inputName).uploadedFilePath(), imageType, 300, 300, true);

        if(newImageName.isEmpty())
        {
            QString error = H::tr("An error occurred while downloading picture. Please, try later");
            tflash(error);
            redirect(H::createUrl({"user", "profile"}));
            return ;
        }

        if(!oldAvatar.isEmpty())
        {
            QFile file("./public/images/avatars/" + oldAvatar);
            if(file.exists())
                file.remove();
            file.close();
        }

        query.prepare("UPDATE `profiles` SET `avatar` = ? WHERE `user_id` = ? LIMIT 1");
        query.addBind(newImageName).addBind(id);
        if(query.exec())
        {
            QString success = H::tr("Profile was successfully updated");
            tflash(success);
            redirect(H::createUrl({"user", "profile"}));
            return ;
        }
        else
        {
            QString error = H::tr("Updating profile failed, sorry");
            tflash(error);
            redirect(H::createUrl({"user", "profile"}));
            return ;
        }
    }

    redirect(H::createUrl({"user", "profile"}));
}

void AccountController::editProfile()
{
    if(httpRequest().method() != Tf::Post || !httpRequest().hasFormItem("id"))
    {
        renderErrorResponse(404);
        return ;
    }

    const int userId = httpRequest().formItemValue("id", "0").toInt();

    if(!userId || !isUserLoggedIn() || !getUser().isAdmin() || userId != getUser().id())
    {
        renderErrorResponse(404);
        return ;
    }

    QStringList allowedNames{"name", "interests", "exp", "about_me", "signature"};

    QString currentItem = "";
    for(const auto& name: allowedNames)
    {
        if(httpRequest().hasFormItem(name))
            currentItem = name;
    }
    if(currentItem.isEmpty())
    {
        renderErrorResponse(404);
        return ;
    }
    QString value = httpRequest().formItemValue(currentItem, "").trimmed();

    TSqlQuery query;
    query.prepare(QString("UPDATE `profiles` SET `%1` = ? WHERE `user_id` = ? LIMIT 1").arg(currentItem));
    query.addBind(value).addBind(userId);

    renderText( query.exec() ? "1" : "0" );

}

void AccountController::showUserProfile(const QString &userId)
{
    const int id = userId.left(userId.indexOf(QRegExp("\\.(?=html)"))).toInt();

    const auto& user = Users::get(id);

    if(user.isNull())
    {
        showFlash(H::tr("User not found"));
        redirect(QUrl("/"));
        return;
    }

    const auto& profile = user.profile();

    const bool& canBeEdited = isUserLoggedIn() && (user.id() == getUser().id() || getUser().isAdmin());

    texport(profile);
    texport(user);
    texport(canBeEdited);

    render("profile");
}

void AccountController::showFlash(const QString& error, const QString& redirectUrl, const QString &warning, const QString &notice, const QString &success)
{
    updateUser();

    tflash(error);
    tflash(warning);
    tflash(notice);
    tflash(success);
    if(!redirectUrl.isEmpty())
        redirect(H::createUrl({"user", redirectUrl}));
    return ;
}

// Don't remove below this line
T_REGISTER_CONTROLLER(accountcontroller)
