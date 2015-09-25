#ifndef ACCOUNTCONTROLLER_H
#define ACCOUNTCONTROLLER_H

#include "applicationcontroller.h"

#include <botan/botan.h>
#include <botan/bcrypt.h>

class T_CONTROLLER_EXPORT AccountController : public ApplicationController
{
    Q_OBJECT

    void showFlash(const QString& error, const QString& redirectUrl = "register", const QString& warning=QString(), const QString& notice=QString(), const QString& success=QString());

public:
    AccountController() { }
    AccountController(const AccountController &other);

public slots:
    void users();
    void form();
    void login();
    void logout();
    void registration();
    void profile();
    void showUserProfile(const QString& userId);
    void editProfile();
    void editProfileAvatar(const QString& userId);
};

T_DECLARE_CONTROLLER(AccountController, accountcontroller)

#endif // ACCOUNTCONTROLLER_H
