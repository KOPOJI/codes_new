#ifndef PRIVATEMESSAGESCONTROLLER_H
#define PRIVATEMESSAGESCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT PrivateMessagesController : public ApplicationController
{
    Q_OBJECT
public:
    PrivateMessagesController() { }
    PrivateMessagesController(const PrivateMessagesController &other);

public slots:
    void inbox();
    void outbox();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &privateMessages = QVariantMap());
    void renderEdit(const QVariantMap &privateMessages = QVariantMap());
};

T_DECLARE_CONTROLLER(PrivateMessagesController, privatemessagescontroller)

#endif // PRIVATEMESSAGESCONTROLLER_H
