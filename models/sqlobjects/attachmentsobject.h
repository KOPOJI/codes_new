#ifndef ATTACHMENTSOBJECT_H
#define ATTACHMENTSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT AttachmentsObject : public TSqlObject, public QSharedData
{
public:
    int id;
    int code_id;
    QString image;
    QDateTime created_at;
    QDateTime updated_at;

    enum PropertyIndex {
        Id = 0,
        CodeId,
        Image,
        CreatedAt,
        UpdatedAt,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("attachments"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(int code_id READ getcode_id WRITE setcode_id)
    T_DEFINE_PROPERTY(int, code_id)
    Q_PROPERTY(QString image READ getimage WRITE setimage)
    T_DEFINE_PROPERTY(QString, image)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
};

#endif // ATTACHMENTSOBJECT_H
