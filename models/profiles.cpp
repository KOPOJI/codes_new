#include <TreeFrogModel>
#include "profiles.h"
#include "profilesobject.h"

Profiles::Profiles()
    : TAbstractModel(), d(new ProfilesObject)
{
    d->id = 0;
    d->user_id = 0;
}

Profiles::Profiles(const Profiles &other)
    : TAbstractModel(), d(new ProfilesObject(*other.d))
{ }

Profiles::Profiles(const ProfilesObject &object)
    : TAbstractModel(), d(new ProfilesObject(object))
{ }

Profiles::~Profiles()
{
    // If the reference count becomes 0,
    // the shared data object 'ProfilesObject' is deleted.
}

int Profiles::id() const
{
    return d->id;
}

QString Profiles::name() const
{
    return d->name;
}

void Profiles::setName(const QString &name)
{
    d->name = name;
}

QString Profiles::interests() const
{
    return d->interests;
}

void Profiles::setInterests(const QString &interests)
{
    d->interests = interests;
}

QString Profiles::exp() const
{
    return d->exp;
}

void Profiles::setExp(const QString &exp)
{
    d->exp = exp;
}

QString Profiles::aboutMe() const
{
    return d->about_me;
}

void Profiles::setAboutMe(const QString &aboutMe)
{
    d->about_me = aboutMe;
}

QString Profiles::signature() const
{
    return d->signature;
}

void Profiles::setSignature(const QString &signature)
{
    d->signature = signature;
}

int Profiles::userId() const
{
    return d->user_id;
}

void Profiles::setUserId(int userId)
{
    d->user_id = userId;
}

QDateTime Profiles::createdAt() const
{
    return d->created_at;
}

QDateTime Profiles::updatedAt() const
{
    return d->updated_at;
}

QString Profiles::avatar() const
{
    return d->avatar;
}

void Profiles::setAvatar(const QString &avatar)
{
    d->avatar = avatar;
}

Profiles &Profiles::operator=(const Profiles &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Profiles Profiles::create(const QString &name, const QString &interests, const QString &exp, const QString &aboutMe, const QString &signature, int userId, const QString &avatar)
{
    ProfilesObject obj;
    obj.name = name;
    obj.interests = interests;
    obj.exp = exp;
    obj.about_me = aboutMe;
    obj.signature = signature;
    obj.user_id = userId;
    obj.avatar = avatar;
    if (!obj.create()) {
        return Profiles();
    }
    return Profiles(obj);
}

Profiles Profiles::create(const QVariantMap &values)
{
    Profiles model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Profiles Profiles::get(const int userId)
{
    TSqlORMapper<ProfilesObject> mapper;
    return Profiles(mapper.findFirstBy(ProfilesObject::UserId, userId));
    //return Profiles(mapper.findByPrimaryKey(id));
}

int Profiles::count()
{
    TSqlORMapper<ProfilesObject> mapper;
    return mapper.findCount();
}

QList<Profiles> Profiles::getAll()
{
    return tfGetModelListByCriteria<Profiles, ProfilesObject>(TCriteria());
}

QJsonArray Profiles::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ProfilesObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ProfilesObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Profiles(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Profiles::modelData()
{
    return d.data();
}

const TModelObject *Profiles::modelData() const
{
    return d.data();
}
