#include "applicationcontroller.h"

ApplicationController::ApplicationController()
    : TActionController()
{ }

ApplicationController::ApplicationController(const ApplicationController &)
    : TActionController()
{ }

Users ApplicationController::getUser() const
{
    if(!isUserLoggedIn())
        return Users();
    return Users::getByIdentityKey(identityKeyOfLoginUser());
}

bool ApplicationController::isUserLoggedIn() const
{
    return !httpRequest().cookie("user_id").isEmpty() || TActionController::isUserLoggedIn();
}

void ApplicationController::updateUser()
{
    static int countActions = 0;
    const int countForUpdate = 10;
    if(isUserLoggedIn() && ++countActions == countForUpdate)
    {
        countActions = 0;
        Users user = TActionController::isUserLoggedIn() ? Users::getByIdentityKey(identityKeyOfLoginUser()) : Users::get(httpRequest().cookie("user_id").toInt());
        if(!TActionController::isUserLoggedIn())
            userLogin(&user);
        if(!user.isNull())
        {
            user.setUpdatedAt(QDateTime::currentDateTime());
            user.update();
        }
    }
}

void ApplicationController::loadLanguage(const bool updateNeeded)
{
    static QStringList languages{"ru", "en"};
    static QString defaultLanguage = languages.first();
    static QString lang = "";

    if(lang.isEmpty() && session()["language"].isNull())
    {
        QFile file("./translations/tr_language.txt");
        if(file.open(QIODevice::ReadOnly))
        {
            session()["language"] = file.readLine().trimmed();
            file.close();
        }
    }

    if(session()["language"].isNull())
        session()["language"] = defaultLanguage;

    if(updateNeeded || lang.isEmpty())
    {
        lang = session()["language"].toString();

        if(!languages.contains(lang))
        {
            lang = languages.first();
            session()["language"] = lang;
        }
    }

    QFile file("./translations/tr_language.txt");
    if(!file.open(QIODevice::WriteOnly))
        return ;

    file.write(lang.toStdString().c_str());

    file.close();
}

ApplicationController::~ApplicationController()
{ }

void ApplicationController::staticInitialize()
{
    loadLanguage(true);
}

void ApplicationController::language(const QString &language)
{
    QStringList languages{"russian", "english"};
    const int MAX_SIZE = 7;
    const int LANG_SIZE = 2;

    if(languages.contains(language.left(MAX_SIZE)))
    {
        QString success = ("Language changed to " + QString(language.left(MAX_SIZE).replace(0,1, language.at(0).toUpper())));
        texport(success);

        redirect(QUrl('/' + language.left(LANG_SIZE) + '/'));
    }

}

void ApplicationController::captcha()
{
    if (httpRequest().method() != Tf::Post)
        return;

    renderText(getCaptcha());
}

void ApplicationController::staticRelease()
{ }


bool ApplicationController::preFilter()
{
    const QStringList languages{"ru", "en"};
    QString path = httpRequest().header().path();

    if(!path.endsWith(".html", Qt::CaseInsensitive) && !path.endsWith('/') && !path.contains("?page=", Qt::CaseInsensitive))
        path += '/';

    if(0 != QRegExp(QString("/(?:%1)/").arg(languages.join('|')), Qt::CaseInsensitive).indexIn(path))
        path  = "/ru" + path;

    if(path != httpRequest().header().path() && !path.contains("language"))
    {
        redirect(QUrl(path), Tf::MovedPermanently);
        return false;
    }

    const QString LANG_ID = path.mid(1, path.indexOf('/', 1) - 1).trimmed();

    QString title = getTitle();
    texport(title);

    Users user = getUser();
    texport(user);

    texport(LANG_ID);

    return true;
}

QString ApplicationController::getCaptcha()
{
    const auto& text = H::getCaptchaCode().toUpper();

    session()["c_id"] = text;

    QByteArray ba = H::getCaptcha(text);

    return ba.toBase64();
}

QString ApplicationController::getTitle()
{
    const QString siteName = "SaveCode.RU";

    QMap<QString, QMap<QString, QString>> titles;

    titles.insert("Account",
        QMap<QString, QString>({
            {"login", H::tr("Sign")},
            {"registration", H::tr("Sign up")},
            {"showUserProfile", H::tr("Show user profile")},
            {"profile", H::tr("Show profile")},
            {"users", H::tr("Users list")}
        })
    );
    titles.insert("Attachments",
        QMap<QString, QString>({
            {"index", H::tr("Listing pictures")},
            {"entry", H::tr("Uploading picture")},
            {"edit", H::tr("Editing picture")},
        })
    );
    titles.insert("Codes",
        QMap<QString, QString>({
            {"show", H::tr("View code")},
            {"entry", H::tr("Adding new code")},
            {"edit", H::tr("Editing code")},
        })
    );
    titles.insert("PrivateMessages",
        QMap<QString, QString>({
            {"login", H::tr("Sign")},
            {"registration", H::tr("Sign up")},
            {"showUserProfile", H::tr("Profile")},
            {"users", H::tr("Users")}
        })
    );

    if(!titles.contains(name()))
        return siteName;

    const auto currentController = titles[name()];

    if(!currentController.contains(activeAction()))
        return siteName; // + " - " + activeAction();

    return siteName + " - " + currentController[activeAction()];
}


// Don't remove below this line
T_REGISTER_CONTROLLER(applicationcontroller)
