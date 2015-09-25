#ifndef PROFILES_H
#define PROFILES_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ProfilesObject;
class QJsonArray;


class T_MODEL_EXPORT Profiles : public TAbstractModel
{
public:
    Profiles();
    Profiles(const Profiles &other);
    Profiles(const ProfilesObject &object);
    ~Profiles();

    int id() const;
    QString name() const;
    void setName(const QString &name);
    QString interests() const;
    void setInterests(const QString &interests);
    QString exp() const;
    void setExp(const QString &exp);
    QString aboutMe() const;
    void setAboutMe(const QString &aboutMe);
    QString signature() const;
    void setSignature(const QString &signature);
    int userId() const;
    void setUserId(int userId);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    QString avatar() const;
    void setAvatar(const QString &avatar);
    Profiles &operator=(const Profiles &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static Profiles create(const QString &name, const QString &interests, const QString &exp, const QString &aboutMe, const QString &signature, int userId, const QString &avatar);
    static Profiles create(const QVariantMap &values);
    static Profiles get(const int &userId);
    static int count();
    static QList<Profiles> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ProfilesObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Profiles)
Q_DECLARE_METATYPE(QList<Profiles>)

#endif // PROFILES_H
