#include "codescontroller.h"
#include "codes.h"


CodesController::CodesController(const CodesController &)
    : ApplicationController()
{ }

void CodesController::index()
{
    updateUser();

    render();
}

void CodesController::show(const QString &pk)
{
    updateUser();

    auto code = Codes::get(pk.left(pk.indexOf(QRegExp("\\.(?=html)"))).toInt());
    texport(code);
    render();
}

void CodesController::entry()
{
    updateUser();

    renderEntry();
}

void CodesController::findByUser(const QString& pk)
{
    updateUser();

    const int id = pk.left(pk.indexOf(QRegExp("\\.(?=html)"))).toInt();
    QString error = "";
    auto user = Users::get(id);
    if(user.isNull())
        error = H::tr("User with this id") + " (" + QString::number(id) + ") " + H::tr("not found");
    auto codes = Codes::userCodes(id);
    if(error.isEmpty() && codes.isEmpty())
        error = "<b>" + user.username() + "</b> " + H::tr("does not have any posts");

    texport(user);
    texport(error);
    texport(codes);
    render("find_by_user");
}

void CodesController::create()
{
    updateUser();

    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("codes");

    auto codes = Codes::create(form);
    if (!codes.isNull())
    {
        if(codes.title().trimmed().isEmpty())
        {
            codes.setTitle(QString("Unnamed #%1").arg(codes.id()));
            codes.update();
        }
        codes.updateCount(httpRequest().queryItemValue("page", "1").toInt());

        //upload pictures
        QList<TMimeEntity> lst = httpRequest().multipartFormData().entityList( "attachments[]" );

        QStringList attachments;

        const auto& regType = QRegExp("jpe?g|png|gif", Qt::CaseInsensitive);
        const auto& regName = QRegularExpression("(?<=\\.)(?:jpe?g|png|gif)$", QRegularExpression::CaseInsensitiveOption | QRegularExpression::UseUnicodePropertiesOption);

        for (QListIterator<TMimeEntity> it(lst); it.hasNext(); )
        {

            TMimeEntity e = it.next();

            QString imageType = e.contentType();

            imageType = imageType.mid(imageType.indexOf('/') + 1).toUpper().trimmed().replace("GIF", "PNG");

            if (!imageType.contains(regType) || !e.originalFileName().contains(regName))
                continue;

            const QString& newImageName = H::imageResize(e.uploadedFilePath(), imageType);

            if(newImageName.isEmpty())
                continue;

            attachments << newImageName;
        }

        bool status = false;

        if(!attachments.isEmpty())
        {
            TSqlQuery query;
            QString q = "INSERT INTO `attachments`(`id`, `code_id`, `image`, `created_at`, `updated_at`) VALUES";
            for(const auto& attach: attachments)
                q += QString("(NULL, %1, '%2', NOW(), NOW()), ").arg(codes.id()).arg(attach);
            status = query.exec(q.left(q.length() - 2));
        }

        QString notice = H::tr("Code was successfully created") + " " + H::tr(status ? "Picture was successfully uploaded" : "An error occurred while downloading picture. Please, try later");

        tflash(notice);
        redirect(H::createUrl({"codes", QString::number(codes.id())}, httpRequest().queryItemValue("page", "1")));
    }
    else
    {
        QString error = H::tr("Failed to create.");
        texport(error);
        renderEntry(form);
    }
}

void CodesController::renderEntry(const QVariantMap &codes)
{
    updateUser();

    auto user = getUser();
    texport(user);

    texport(codes);
    render("entry");
}

void CodesController::edit(const QString &pk)
{
    updateUser();

    const int id = pk.left(pk.indexOf(QRegExp("\\.(?=html)"))).toInt();

    auto codes = Codes::get(id);

    if (!codes.isNull() && codes.canBeEdited(isUserLoggedIn()))
    {
        renderEdit(codes.toVariantMap());
    }
    else
    {
        redirect(H::createUrl({"codes", QString::number(id)}, httpRequest().queryItemValue("page", "1")));
    }
}

void CodesController::save(const QString &pk)
{
    updateUser();

    if (httpRequest().method() != Tf::Post) {
        return;
    }

    const int id = pk.left(pk.indexOf(QRegExp("\\.(?=html)"))).toInt();

    QString error;
    auto codes = Codes::get(id);
    if (codes.isNull())
    {
        error = H::tr("Original data not found. It may have been updated/removed by another transaction.");
        tflash(error);
        redirect(H::createUrl({"codes", "edit", QString::number(id)}, httpRequest().queryItemValue("page", "1")));
        return;
    }

    auto form = httpRequest().formItems("codes");

    codes.setProperties(form);
    if (codes.save())
    {
        //update cashed code
        codes.get(codes.id(), true);

        //upload pictures
        QList<TMimeEntity> lst = httpRequest().multipartFormData().entityList( "attachments[]" );

        QStringList attachments;

        const auto& regType = QRegExp("jpe?g|png|gif", Qt::CaseInsensitive);
        const auto& regName = QRegularExpression("(?<=\\.)(?:jpe?g|png|gif)$", QRegularExpression::CaseInsensitiveOption | QRegularExpression::UseUnicodePropertiesOption);

        for (QListIterator<TMimeEntity> it(lst); it.hasNext(); )
        {

            TMimeEntity e = it.next();

            QString imageType = e.contentType();

            imageType = imageType.mid(imageType.indexOf('/') + 1).toUpper().trimmed().replace("GIF", "PNG");

            if (!imageType.contains(regType) || !e.originalFileName().contains(regName))
                continue;

            const QString& newImageName = H::imageResize(e.uploadedFilePath(), imageType);

            if(newImageName.isEmpty())
                continue;

            attachments << newImageName;
        }

        bool status = false;

        if(!attachments.isEmpty())
        {
            TSqlQuery query;
            QString q = "INSERT INTO `attachments`(`id`, `code_id`, `image`, `created_at`, `updated_at`) VALUES";
            for(const auto& attach: attachments)
                q += QString("(NULL, %1, '%2', NOW(), NOW()), ").arg(codes.id()).arg(attach);
            status = query.exec(q.left(q.length() - 2));
        }

        QString notice = H::tr("Code was successfully created") + " " + H::tr(status ? "Picture was successfully uploaded" : "An error occurred while downloading picture. Please, try later");

        tflash(notice);
        redirect(H::createUrl({"codes", QString::number(id)}, httpRequest().queryItemValue("page", "1")));
    }
    else
    {
        error = H::tr("Failed to update.");
        texport(error);
        renderEdit(form);
    }
}

void CodesController::renderEdit(const QVariantMap &codes)
{
    updateUser();

    texport(codes);
    render("edit");
}

void CodesController::remove(const QString &pk)
{
    updateUser();

    if (httpRequest().method() != Tf::Post) {
        return;
    }

    const int id = pk.left(pk.indexOf(QRegExp("\\.(?=html)"))).toInt();

    auto codes = Codes::get(id);
    codes.remove();
    redirect(H::createUrl({"codes", QString::number(id)}, httpRequest().queryItemValue("page", "1")));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(codescontroller)
