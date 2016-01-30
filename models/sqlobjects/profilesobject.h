#ifndef PROFILESOBJECT_H
#define PROFILESOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ProfilesObject : public TSqlObject, public QSharedData
{
public:
    int id;
    QString name;
    QString interests;
    QString exp;
    QString about_me;
    QString signature;
    int user_id;
    QDateTime created_at;
    QDateTime updated_at;
    QString avatar;

    enum PropertyIndex {
        Id = 0,
        Name,
        Interests,
        Exp,
        AboutMe,
        Signature,
        UserId,
        CreatedAt,
        UpdatedAt,
        Avatar,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("profiles"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString name READ getname WRITE setname)
    T_DEFINE_PROPERTY(QString, name)
    Q_PROPERTY(QString interests READ getinterests WRITE setinterests)
    T_DEFINE_PROPERTY(QString, interests)
    Q_PROPERTY(QString exp READ getexp WRITE setexp)
    T_DEFINE_PROPERTY(QString, exp)
    Q_PROPERTY(QString about_me READ getabout_me WRITE setabout_me)
    T_DEFINE_PROPERTY(QString, about_me)
    Q_PROPERTY(QString signature READ getsignature WRITE setsignature)
    T_DEFINE_PROPERTY(QString, signature)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString avatar READ getavatar WRITE setavatar)
    T_DEFINE_PROPERTY(QString, avatar)
};

#endif // PROFILESOBJECT_H
