#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include <TActionController>
#include <TWebApplication>
#include "applicationhelper.h"
#include "codes.h"

class T_CONTROLLER_EXPORT ApplicationController : public TActionController
{
    Q_OBJECT
public:
    ApplicationController();
    ApplicationController(const ApplicationController &other);


    Users getUser() const;

    virtual bool isUserLoggedIn() const;
    void updateUser();
    void loadLanguage(const bool updateNeeded = false);


    virtual ~ApplicationController();

public slots:
    void staticInitialize();
    void staticRelease();

    void language(const QString &language);

    void captcha();


protected:
    virtual bool preFilter();

    virtual QString getTitle();
    virtual QString getCaptcha();
};

T_DECLARE_CONTROLLER(ApplicationController, applicationcontroller)

#endif // APPLICATIONCONTROLLER_H
