#ifndef CODES_H
#define CODES_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>
#include <TPaginator>

#include "users.h"



class TModelObject;
class CodesObject;
class QJsonArray;


class T_MODEL_EXPORT Codes : public TAbstractModel
{
public:
    Codes();
    Codes(const Codes &other);
    Codes(const CodesObject &object);
    ~Codes();

    int id() const;
    QString title() const;
    void setTitle(const QString &title);
    QString code() const;
    void setCode(const QString &code);
    QString codeUrl() const;
    void setCodeUrl(const QString &codeUrl);
    int status() const;
    void setStatus(int status);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    int editable() const;
    void setEditable(int editable);
    int userId() const;
    QString author() const;
    void setUserId(int userId);
    QString showFrom() const;
    void setShowFrom(const QString &showFrom);
    Codes &operator=(const Codes &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static Codes create(const QString &title, const QString &code, const QString &codeUrl, int status, int editable, int userId, const QString &showFrom);
    static Codes create(const QVariantMap &values);
    static Codes get(int id, const bool& updateNeeded = false);
    static int count(const bool& updateNeeded = false);
    static QList<Codes> getAll();
    static QList<Codes> getAll(const int &page, const bool& updateNeeded = false);
    static QJsonArray getAllJson();

    static int pageSize() ;
    static int pagesCount() ;

    static void updateCount(const int& page = 1);

    static QList<Codes> userCodes(const int& userId);
    static int userCodesCount(const int& userId);

    bool canBeEdited(const bool &isUserLogged) const;

private:
    QSharedDataPointer<CodesObject> d;
    static const int _pageSize = 20;

    TModelObject *modelData();
    const TModelObject *modelData() const;

};

Q_DECLARE_METATYPE(Codes)
Q_DECLARE_METATYPE(QList<Codes>)

#endif // CODES_H
