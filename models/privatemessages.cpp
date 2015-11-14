#include <TreeFrogModel>
#include "privatemessages.h"
#include "privatemessagesobject.h"

PrivateMessages::PrivateMessages()
    : TAbstractModel(), d(new PrivateMessagesObject)
{
    d->id = 0;
    d->user_from_id = 0;
    d->user_to_id = 0;
    d->deleted_by_from_user = 0;
    d->deleted_by_to_user = 0;
    d->read = 0;
    d->to_message_id = 0;
}

PrivateMessages::PrivateMessages(const PrivateMessages &other)
    : TAbstractModel(), d(new PrivateMessagesObject(*other.d))
{ }

PrivateMessages::PrivateMessages(const PrivateMessagesObject &object)
    : TAbstractModel(), d(new PrivateMessagesObject(object))
{ }

PrivateMessages::~PrivateMessages()
{
    // If the reference count becomes 0,
    // the shared data object 'PrivateMessagesObject' is deleted.
}


Users PrivateMessages::userTo()
{
    if(!d->user_to_id)
        return Users();
    return Users::get(d->user_to_id);
}
Users PrivateMessages::userFrom()
{
    if(!d->user_from_id)
        return Users();
    return Users::get(d->user_from_id);
}

int PrivateMessages::id() const
{
    return d->id;
}

int PrivateMessages::userFromId() const
{
    return d->user_from_id;
}

void PrivateMessages::setUserFromId(int userFromId)
{
    d->user_from_id = userFromId;
}

int PrivateMessages::userToId() const
{
    return d->user_to_id;
}

void PrivateMessages::setUserToId(int userToId)
{
    d->user_to_id = userToId;
}

QString PrivateMessages::title() const
{
    return d->title;
}

void PrivateMessages::setTitle(const QString &title)
{
    d->title = title;
}

QString PrivateMessages::text() const
{
    return d->text;
}

void PrivateMessages::setText(const QString &text)
{
    d->text = text;
}

QString PrivateMessages::file() const
{
    return d->file;
}

void PrivateMessages::setFile(const QString &file)
{
    d->file = file;
}

int PrivateMessages::deletedByFromUser() const
{
    return d->deleted_by_from_user;
}

void PrivateMessages::setDeletedByFromUser(int deletedByFromUser)
{
    d->deleted_by_from_user = deletedByFromUser;
}

int PrivateMessages::deletedByToUser() const
{
    return d->deleted_by_to_user;
}

void PrivateMessages::setDeletedByToUser(int deletedByToUser)
{
    d->deleted_by_to_user = deletedByToUser;
}

int PrivateMessages::read() const
{
    return d->read;
}

void PrivateMessages::setRead(int read)
{
    d->read = read;
}

QDateTime PrivateMessages::createdAt() const
{
    return d->created_at;
}

QDateTime PrivateMessages::updatedAt() const
{
    return d->updated_at;
}

int PrivateMessages::toMessageId() const
{
    return d->to_message_id;
}

void PrivateMessages::setToMessageId(int toMessageId)
{
    d->to_message_id = toMessageId;
}

PrivateMessages &PrivateMessages::operator=(const PrivateMessages &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

PrivateMessages PrivateMessages::create(int userFromId, int userToId, const QString &title, const QString &text, const QString &file, int deletedByFromUser, int deletedByToUser, int read, int toMessageId)
{
    PrivateMessagesObject obj;
    obj.user_from_id = userFromId;
    obj.user_to_id = userToId;
    obj.title = title;
    obj.text = text;
    obj.file = file;
    obj.deleted_by_from_user = deletedByFromUser;
    obj.deleted_by_to_user = deletedByToUser;
    obj.read = read;
    obj.to_message_id = toMessageId;
    if (!obj.create()) {
        return PrivateMessages();
    }
    return PrivateMessages(obj);
}

PrivateMessages PrivateMessages::create(const QVariantMap &values)
{
    PrivateMessages model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

PrivateMessages PrivateMessages::get(int id)
{
    TSqlORMapper<PrivateMessagesObject> mapper;
    return PrivateMessages(mapper.findByPrimaryKey(id));
}

int PrivateMessages::count()
{
    TSqlORMapper<PrivateMessagesObject> mapper;
    return mapper.findCount();
}

int PrivateMessages::count(const int& userId)
{
    TSqlQuery query;
    query.prepare("SELECT COUNT(1) FROM `private_messages` WHERE `user_to_id` = ? AND `read` = ?");
    query.addBind(userId).addBind(false);
    query.exec();
    return query.next() ? query.value(0).toInt() : 0;
}

QList<PrivateMessages> PrivateMessages::getAll()
{
    return tfGetModelListByCriteria<PrivateMessages, PrivateMessagesObject>(TCriteria());
}

QList<PrivateMessages> PrivateMessages::getAll(const int &userId, const bool &inbox)
{
    return tfGetModelListByCriteria<PrivateMessages, PrivateMessagesObject>(TCriteria(inbox ? PrivateMessagesObject::UserToId : PrivateMessagesObject::UserFromId, userId));
}

QJsonArray PrivateMessages::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<PrivateMessagesObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<PrivateMessagesObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(PrivateMessages(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *PrivateMessages::modelData()
{
    return d.data();
}

const TModelObject *PrivateMessages::modelData() const
{
    return d.data();
}
