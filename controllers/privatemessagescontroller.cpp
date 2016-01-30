#include "privatemessagescontroller.h"
#include "privatemessages.h"


PrivateMessagesController::PrivateMessagesController(const PrivateMessagesController &)
    : ApplicationController()
{ }

void PrivateMessagesController::index()
{
    updateUser();
    const auto& user = getUser();


    QList<PrivateMessages> privateMessagesList = PrivateMessages::getAll(user.id(), httpRequest().header().path().contains("inbox"));
    texport(privateMessagesList);

    QString action = httpRequest().header().path().contains("inbox") ? "inbox" : "outbox";
    texport(action);

    render("index");
}

void PrivateMessagesController::show(const QString &pk)
{
    auto message = PrivateMessages::get(pk.left(pk.indexOf(QRegExp("\\.(?=html)"))).toInt());
    texport(message);

    QString action = httpRequest().header().path().contains("inbox") ? "inbox" : "outbox";
    texport(action);

    render();
}

void PrivateMessagesController::entry()
{
    renderEntry();
}

void PrivateMessagesController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("privateMessages");
    auto privateMessages = PrivateMessages::create(form);
    if (!privateMessages.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", privateMessages.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void PrivateMessagesController::renderEntry(const QVariantMap &privateMessages)
{
    texport(privateMessages);
    render("entry");
}

void PrivateMessagesController::edit(const QString &pk)
{
    auto privateMessages = PrivateMessages::get(pk.toInt());
    if (!privateMessages.isNull()) {
        renderEdit(privateMessages.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void PrivateMessagesController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    auto privateMessages = PrivateMessages::get(pk.toInt());
    if (privateMessages.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("privateMessages");
    privateMessages.setProperties(form);
    if (privateMessages.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void PrivateMessagesController::renderEdit(const QVariantMap &privateMessages)
{
    texport(privateMessages);
    render("edit");
}

void PrivateMessagesController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto privateMessages = PrivateMessages::get(pk.toInt());
    privateMessages.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(privatemessagescontroller)
