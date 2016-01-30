#ifndef PRIVATEMESSAGESOBJECT_H
#define PRIVATEMESSAGESOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT PrivateMessagesObject : public TSqlObject, public QSharedData
{
public:
    int id;
    int user_from_id;
    int user_to_id;
    QString title;
    QString text;
    QString file;
    int deleted_by_from_user;
    int deleted_by_to_user;
    int read;
    QDateTime created_at;
    QDateTime updated_at;
    int to_message_id;

    enum PropertyIndex {
        Id = 0,
        UserFromId,
        UserToId,
        Title,
        Text,
        File,
        DeletedByFromUser,
        DeletedByToUser,
        Read,
        CreatedAt,
        UpdatedAt,
        ToMessageId,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("private_messages"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(int user_from_id READ getuser_from_id WRITE setuser_from_id)
    T_DEFINE_PROPERTY(int, user_from_id)
    Q_PROPERTY(int user_to_id READ getuser_to_id WRITE setuser_to_id)
    T_DEFINE_PROPERTY(int, user_to_id)
    Q_PROPERTY(QString title READ gettitle WRITE settitle)
    T_DEFINE_PROPERTY(QString, title)
    Q_PROPERTY(QString text READ gettext WRITE settext)
    T_DEFINE_PROPERTY(QString, text)
    Q_PROPERTY(QString file READ getfile WRITE setfile)
    T_DEFINE_PROPERTY(QString, file)
    Q_PROPERTY(int deleted_by_from_user READ getdeleted_by_from_user WRITE setdeleted_by_from_user)
    T_DEFINE_PROPERTY(int, deleted_by_from_user)
    Q_PROPERTY(int deleted_by_to_user READ getdeleted_by_to_user WRITE setdeleted_by_to_user)
    T_DEFINE_PROPERTY(int, deleted_by_to_user)
    Q_PROPERTY(int read READ getread WRITE setread)
    T_DEFINE_PROPERTY(int, read)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(int to_message_id READ getto_message_id WRITE setto_message_id)
    T_DEFINE_PROPERTY(int, to_message_id)
};

#endif // PRIVATEMESSAGESOBJECT_H
