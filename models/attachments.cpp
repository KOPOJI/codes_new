#include <TreeFrogModel>
#include "attachments.h"
#include "attachmentsobject.h"

Attachments::Attachments()
    : TAbstractModel(), d(new AttachmentsObject)
{
    d->id = 0;
    d->code_id = 0;
}

Attachments::Attachments(const Attachments &other)
    : TAbstractModel(), d(new AttachmentsObject(*other.d))
{ }

Attachments::Attachments(const AttachmentsObject &object)
    : TAbstractModel(), d(new AttachmentsObject(object))
{ }

Attachments::~Attachments()
{
    // If the reference count becomes 0,
    // the shared data object 'AttachmentsObject' is deleted.
}

Codes Attachments::code() const
{
    if(!codeId())
        return Codes();
    return Codes::get(codeId());
}

bool Attachments::canBeDeleted(const Users& user) const
{
    return !user.isNull();
}

int Attachments::id() const
{
    return d->id;
}

int Attachments::codeId() const
{
    return d->code_id;
}

void Attachments::setCodeId(int codeId)
{
    d->code_id = codeId;
}

QString Attachments::image() const
{
    return d->image;
}

void Attachments::setImage(const QString &image)
{
    d->image = image;
}

QDateTime Attachments::createdAt() const
{
    return d->created_at;
}

QDateTime Attachments::updatedAt() const
{
    return d->updated_at;
}

Attachments &Attachments::operator=(const Attachments &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Attachments Attachments::create(int codeId, const QString &image)
{
    AttachmentsObject obj;
    obj.code_id = codeId;
    obj.image = image;
    if (!obj.create()) {
        return Attachments();
    }
    return Attachments(obj);
}

Attachments Attachments::create(const QVariantMap &values)
{
    Attachments model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

const Attachments &Attachments::get(int id, const bool updateNeeded)
{
    static Attachments attach;
    static int currentId = 0;
    if(attach.isNull() || id != currentId || updateNeeded)
    {
        currentId = id;
        TSqlORMapper<AttachmentsObject> mapper;
        attach = Attachments(mapper.findByPrimaryKey(id));
    }
    return attach;
}

int Attachments::count()
{
    TSqlORMapper<AttachmentsObject> mapper;
    return mapper.findCount();
}

QList<Attachments> Attachments::getAll()
{
    return tfGetModelListByCriteria<Attachments, AttachmentsObject>(TCriteria());
}

const QList<Attachments>& Attachments::getAll(const int codeId, const bool updateNeeded)
{
    static QList<Attachments> attachments;
    static int currentCodeId = 0;

    if(currentCodeId != codeId || updateNeeded)
    {
        currentCodeId = codeId;
        attachments = tfGetModelListByCriteria<Attachments, AttachmentsObject>(TCriteria(AttachmentsObject::CodeId, codeId), AttachmentsObject::Id, Tf::DescendingOrder);
    }
    return attachments;
}

QJsonArray Attachments::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<AttachmentsObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<AttachmentsObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Attachments(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Attachments::modelData()
{
    return d.data();
}

const TModelObject *Attachments::modelData() const
{
    return d.data();
}
