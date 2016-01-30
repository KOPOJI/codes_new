#include <TreeFrogModel>
#include "codes.h"
#include "codesobject.h"

Codes::Codes()
    : TAbstractModel(), d(new CodesObject)
{
    d->id = 0;
    d->status = 0;
    d->editable = 0;
    d->user_id = 0;
}

Codes::Codes(const Codes &other)
    : TAbstractModel(), d(new CodesObject(*other.d))
{ }

Codes::Codes(const CodesObject &object)
    : TAbstractModel(), d(new CodesObject(object))
{ }

Codes::~Codes()
{
    // If the reference count becomes 0,
    // the shared data object 'CodesObject' is deleted.
}

int Codes::id() const
{
    return d->id;
}

QString Codes::title() const
{
    QString ret = d->title;
    if(ret.isEmpty())
        ret = H::tr("Code") + " #" + QString::number(id());
    return ret.replace(QRegExp("unnamed(?=\\s*#\\d+)", Qt::CaseInsensitive), H::tr("Code") + " ");
}

void Codes::setTitle(const QString &title)
{
    d->title = title;
}

QString Codes::code() const
{
    return d->code;
}

void Codes::setCode(const QString &code)
{
    d->code = code;
}

QString Codes::codeUrl() const
{
    return d->code_url;
}

void Codes::setCodeUrl(const QString &codeUrl)
{
    d->code_url = codeUrl;
}

int Codes::status() const
{
    return d->status;
}

void Codes::setStatus(int status)
{
    d->status = status;
}

QDateTime Codes::createdAt() const
{
    return d->created_at;
}

QDateTime Codes::updatedAt() const
{
    return d->updated_at;
}

int Codes::editable() const
{
    return d->editable;
}

void Codes::setEditable(int editable)
{
    d->editable = editable;
}

int Codes::userId() const
{
    return d->user_id;
}

void Codes::setUserId(int userId)
{
    d->user_id = userId;
}

QString Codes::showFrom() const
{
    return d->show_from;
}

void Codes::setShowFrom(const QString &showFrom)
{
    d->show_from = showFrom;
}

Codes &Codes::operator=(const Codes &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Codes Codes::create(const QString &title, const QString &code, const QString &codeUrl, int status, int editable, int userId, const QString &showFrom)
{
    CodesObject obj;
    obj.title = title;
    obj.code = code;
    obj.code_url = codeUrl;
    obj.status = status;
    obj.editable = editable;
    obj.user_id = userId;
    obj.show_from = showFrom;
    if (!obj.create()) {
        return Codes();
    }
    return Codes(obj);
}

Codes Codes::create(const QVariantMap &values)
{
    Codes model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

const Codes &Codes::get(int id, const bool updateNeeded)
{
    static Codes code;
    static int currentId = 0;
    if(code.isNull() || currentId != id || updateNeeded)
    {
        currentId = id;
        TSqlORMapper<CodesObject> mapper;
        code = Codes(mapper.findByPrimaryKey(id));
    }
    return code;
}
QString Codes::author() const
{
    if(!userId())
        return H::tr("Guest");
    Users user = Users::get(userId());
    return user.isNull() ? H::tr("Guest") : user.username();
}

int Codes::count(const bool updateNeeded)
{
    static int codesCnt = 0;
    if(!codesCnt || updateNeeded)
    {
        TSqlORMapper<CodesObject> mapper;
        codesCnt = mapper.findCount();
    }
    return codesCnt;
}

void Codes::updateCount(const int page)
{
    count(true);
    getAll(page, true);
}
bool Codes::canBeEdited() const
{
    if(!userId())
        return true;

    auto user = Users::get(userId());
    return !user.isNull() || user.isAdmin();
}

int Codes::pageSize()
{
    return _pageSize;
}

int Codes::pagesCount()
{
    return std::ceil(count() * 1. / pageSize());
}

int Codes::userCodesCount(const int userId, const bool updateNeeded)
{
    static int codesCnt = -1;

    if(updateNeeded || codesCnt == -1)
    {
        TSqlQuery query;
        query.prepare("SELECT COUNT(1) FROM `codes` WHERE `user_id` = ?");
        query.addBind(userId);
        query.exec();
        if(!query.next())
            return 0;
        codesCnt = query.value(0).toInt();
    }

    return codesCnt;
}
QList<Codes> Codes::userCodes(const int userId)
{
    return tfGetModelListByCriteria<Codes, CodesObject>(TCriteria(CodesObject::UserId, userId));
}

QList<Codes> Codes::getAll()
{
    return tfGetModelListByCriteria<Codes, CodesObject>(TCriteria(), CodesObject::Id, Tf::DescendingOrder);
}

const QList<Codes> &Codes::getAll(const int page, const bool updateNeeded)
{
    static int currentPage = page;
    static QList<Codes> codes = QList<Codes>();
    //current page is wrong
    if(page > pagesCount() || page < 1)
        return codes;

    if(currentPage != page || codes.isEmpty() || updateNeeded)
    {
        currentPage = page;
        codes = tfGetModelListByCriteria<Codes, CodesObject>(TCriteria(), CodesObject::Id, Tf::DescendingOrder, pageSize(), std::abs((page - 1) * pageSize()));
    }
    return codes;
}

QJsonArray Codes::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<CodesObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<CodesObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Codes(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Codes::modelData()
{
    return d.data();
}

const TModelObject *Codes::modelData() const
{
    return d.data();
}
