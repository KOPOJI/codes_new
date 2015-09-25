#ifndef ATTACHMENTS_H
#define ATTACHMENTS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

#include "codes.h"

class TModelObject;
class AttachmentsObject;
class QJsonArray;


class T_MODEL_EXPORT Attachments : public TAbstractModel
{
public:
    Attachments();
    Attachments(const Attachments &other);
    Attachments(const AttachmentsObject &object);
    ~Attachments();

    Codes code() const;

    int id() const;
    int codeId() const;
    void setCodeId(int codeId);
    QString image() const;
    void setImage(const QString &image);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    Attachments &operator=(const Attachments &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    bool canBeDeleted(const Users &user) const;
    static Attachments create(int codeId, const QString &image);
    static Attachments create(const QVariantMap &values);
    static Attachments get(int id);
    static int count();
    static QList<Attachments> getAll();
    static QList<Attachments> getAll(const int &codeId);
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<AttachmentsObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Attachments)
Q_DECLARE_METATYPE(QList<Attachments>)

#endif // ATTACHMENTS_H
