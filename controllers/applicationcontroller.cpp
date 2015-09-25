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

void ApplicationController::updateUser()
{
    if(isUserLoggedIn())
    {
        Users user = Users::getByIdentityKey(identityKeyOfLoginUser());
        if(!user.isNull())
        {
            user.setUpdatedAt(QDateTime::currentDateTime());
            user.update();
        }
    }
}

void ApplicationController::loadLanguage(const bool &updateNeeded)
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

    if(languages.contains(language.left(MAX_SIZE)))
    {
        session()["language"] = language.left(2);
        loadLanguage(true);
        ApplicationHelper::language(true);
    }

    QString success = ("Language changed to " + QString(language.left(MAX_SIZE).replace(0,1, language.at(0).toUpper())));
    tflash(success);

    redirect(QUrl("/"));
}



void ApplicationController::staticRelease()
{ }


bool ApplicationController::preFilter()
{
    return true;
}


// Don't remove below this line
T_REGISTER_CONTROLLER(applicationcontroller)
