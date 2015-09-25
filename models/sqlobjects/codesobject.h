#ifndef CODESOBJECT_H
#define CODESOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT CodesObject : public TSqlObject, public QSharedData
{
public:
    int id;
    QString title;
    QString code;
    QString code_url;
    int status;
    QDateTime created_at;
    QDateTime updated_at;
    int editable;
    int user_id;
    QString show_from;

    enum PropertyIndex {
        Id = 0,
        Title,
        Code,
        CodeUrl,
        Status,
        CreatedAt,
        UpdatedAt,
        Editable,
        UserId,
        ShowFrom,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("codes"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString title READ gettitle WRITE settitle)
    T_DEFINE_PROPERTY(QString, title)
    Q_PROPERTY(QString code READ getcode WRITE setcode)
    T_DEFINE_PROPERTY(QString, code)
    Q_PROPERTY(QString code_url READ getcode_url WRITE setcode_url)
    T_DEFINE_PROPERTY(QString, code_url)
    Q_PROPERTY(int status READ getstatus WRITE setstatus)
    T_DEFINE_PROPERTY(int, status)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(int editable READ geteditable WRITE seteditable)
    T_DEFINE_PROPERTY(int, editable)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(QString show_from READ getshow_from WRITE setshow_from)
    T_DEFINE_PROPERTY(QString, show_from)
};

#endif // CODESOBJECT_H
