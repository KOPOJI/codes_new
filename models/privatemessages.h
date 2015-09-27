#ifndef PRIVATEMESSAGES_H
#define PRIVATEMESSAGES_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

#include "users.h"

class TModelObject;
class PrivateMessagesObject;
class QJsonArray;


class T_MODEL_EXPORT PrivateMessages : public TAbstractModel
{
public:
    PrivateMessages();
    PrivateMessages(const PrivateMessages &other);
    PrivateMessages(const PrivateMessagesObject &object);
    ~PrivateMessages();

    Users userTo();
    Users userFrom();
    int id() const;
    int userFromId() const;
    void setUserFromId(int userFromId);
    int userToId() const;
    void setUserToId(int userToId);
    QString title() const;
    void setTitle(const QString &title);
    QString text() const;
    void setText(const QString &text);
    QString file() const;
    void setFile(const QString &file);
    int deletedByFromUser() const;
    void setDeletedByFromUser(int deletedByFromUser);
    int deletedByToUser() const;
    void setDeletedByToUser(int deletedByToUser);
    int read() const;
    void setRead(int read);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    int toMessageId() const;
    void setToMessageId(int toMessageId);
    PrivateMessages &operator=(const PrivateMessages &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static PrivateMessages create(int userFromId, int userToId, const QString &title, const QString &text, const QString &file, int deletedByFromUser, int deletedByToUser, int read, int toMessageId);
    static PrivateMessages create(const QVariantMap &values);
    static PrivateMessages get(int id);
    static int count();
    static QList<PrivateMessages> getAll();
    static QList<PrivateMessages> getAll(const int& userId, const bool& inbox = true);
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<PrivateMessagesObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(PrivateMessages)
Q_DECLARE_METATYPE(QList<PrivateMessages>)

#endif // PRIVATEMESSAGES_H
