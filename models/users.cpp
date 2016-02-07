#include <TreeFrogModel>
#include "users.h"
#include "usersobject.h"

Users::Users()
    : TAbstractUser(), TAbstractModel(), d(new UsersObject)
{
    d->id = 0;
    d->sign_in_count = 0;
    d->failed_attempts = 0;
}

Users::Users(const Users &other)
    : TAbstractUser(), TAbstractModel(), d(new UsersObject(*other.d))
{ }

Users::Users(const UsersObject &object)
    : TAbstractUser(), TAbstractModel(), d(new UsersObject(object))
{ }


Users::~Users()
{
    // If the reference count becomes 0,
    // the shared data object 'UsersObject' is deleted.
}

int Users::id() const
{
    return d->id;
}

QString Users::username() const
{
    return d->username;
}

void Users::setUsername(const QString &username)
{
    d->username = username;
}

QString Users::email() const
{
    return d->email;
}

void Users::setEmail(const QString &email)
{
    d->email = email;
}

QString Users::encryptedPassword() const
{
    return d->encrypted_password;
}

void Users::setEncryptedPassword(const QString &encryptedPassword)
{
    d->encrypted_password = encryptedPassword;
}

QString Users::resetPasswordToken() const
{
    return d->reset_password_token;
}

void Users::setResetPasswordToken(const QString &resetPasswordToken)
{
    d->reset_password_token = resetPasswordToken;
}

QDateTime Users::resetPasswordSentAt() const
{
    return d->reset_password_sent_at;
}

void Users::setResetPasswordSentAt(const QDateTime &resetPasswordSentAt)
{
    d->reset_password_sent_at = resetPasswordSentAt;
}

QDateTime Users::rememberCreatedAt() const
{
    return d->remember_created_at;
}

void Users::setRememberCreatedAt(const QDateTime &rememberCreatedAt)
{
    d->remember_created_at = rememberCreatedAt;
}

int Users::signInCount() const
{
    return d->sign_in_count;
}

void Users::setSignInCount(int signInCount)
{
    d->sign_in_count = signInCount;
}

QDateTime Users::currentSignInAt() const
{
    return d->current_sign_in_at;
}

void Users::setCurrentSignInAt(const QDateTime &currentSignInAt)
{
    d->current_sign_in_at = currentSignInAt;
}

QDateTime Users::lastSignInAt() const
{
    return d->last_sign_in_at;
}

void Users::setLastSignInAt(const QDateTime &lastSignInAt)
{
    d->last_sign_in_at = lastSignInAt;
}

QString Users::currentSignInIp() const
{
    return d->current_sign_in_ip;
}

void Users::setCurrentSignInIp(const QString &currentSignInIp)
{
    d->current_sign_in_ip = currentSignInIp;
}

QString Users::lastSignInIp() const
{
    return d->last_sign_in_ip;
}

void Users::setLastSignInIp(const QString &lastSignInIp)
{
    d->last_sign_in_ip = lastSignInIp;
}

QString Users::confirmationToken() const
{
    return d->confirmation_token;
}

void Users::setConfirmationToken(const QString &confirmationToken)
{
    d->confirmation_token = confirmationToken;
}

QDateTime Users::confirmedAt() const
{
    return d->confirmed_at;
}

void Users::setConfirmedAt(const QDateTime &confirmedAt)
{
    d->confirmed_at = confirmedAt;
}

QDateTime Users::confirmationSentAt() const
{
    return d->confirmation_sent_at;
}

void Users::setConfirmationSentAt(const QDateTime &confirmationSentAt)
{
    d->confirmation_sent_at = confirmationSentAt;
}

QString Users::unconfirmedEmail() const
{
    return d->unconfirmed_email;
}

void Users::setUnconfirmedEmail(const QString &unconfirmedEmail)
{
    d->unconfirmed_email = unconfirmedEmail;
}

int Users::failedAttempts() const
{
    return d->failed_attempts;
}

void Users::setFailedAttempts(int failedAttempts)
{
    d->failed_attempts = failedAttempts;
}

QString Users::unlockToken() const
{
    return d->unlock_token;
}

void Users::setUnlockToken(const QString &unlockToken)
{
    d->unlock_token = unlockToken;
}

QDateTime Users::lockedAt() const
{
    return d->locked_at;
}

void Users::setLockedAt(const QDateTime &lockedAt)
{
    d->locked_at = lockedAt;
}
void Users::setUpdatedAt(const QDateTime &updatedAt)
{
    d->updated_at = updatedAt;
}

QDateTime Users::createdAt() const
{
    return d->created_at;
}

QDateTime Users::updatedAt() const
{
    return d->updated_at;
}

Users &Users::operator=(const Users &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Users Users::authenticate(const QString &email, const QString &password)
{
    if (email.isEmpty() || password.isEmpty())
        return Users();

    TSqlORMapper<UsersObject> mapper;
    UsersObject obj = mapper.findFirst(TCriteria(UsersObject::Email, email));
    if (obj.isNull() || !Botan::check_bcrypt(password.toStdString(), obj.encrypted_password.toStdString())) {
        obj.clear();
        qDebug() << obj;
    }
    return Users(obj);
}

Users Users::create(const QString &username, const QString &email, const QString &encryptedPassword, const QString &resetPasswordToken, const QDateTime &resetPasswordSentAt, const QDateTime &rememberCreatedAt, int signInCount, const QDateTime &currentSignInAt, const QDateTime &lastSignInAt, const QString &currentSignInIp, const QString &lastSignInIp, const QString &confirmationToken, const QDateTime &confirmedAt, const QDateTime &confirmationSentAt, const QString &unconfirmedEmail, int failedAttempts, const QString &unlockToken, const QDateTime &lockedAt)
{
    UsersObject obj;
    obj.username = username;
    obj.email = email;
    obj.encrypted_password = encryptedPassword;
    obj.reset_password_token = resetPasswordToken;
    obj.reset_password_sent_at = resetPasswordSentAt;
    obj.remember_created_at = rememberCreatedAt;
    obj.sign_in_count = signInCount;
    obj.current_sign_in_at = currentSignInAt;
    obj.last_sign_in_at = lastSignInAt;
    obj.current_sign_in_ip = currentSignInIp;
    obj.last_sign_in_ip = lastSignInIp;
    obj.confirmation_token = confirmationToken;
    obj.confirmed_at = confirmedAt;
    obj.confirmation_sent_at = confirmationSentAt;
    obj.unconfirmed_email = unconfirmedEmail;
    obj.failed_attempts = failedAttempts;
    obj.unlock_token = unlockToken;
    obj.locked_at = lockedAt;
    if (!obj.create()) {
        return Users();
    }
    return Users(obj);
}

Users Users::create(const QVariantMap &values)
{
    Users model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

const Users &Users::get(int id, const bool updateNeeded)
{
    static Users user;
    static int currentId = 0;
    if(user.isNull() || currentId != id || updateNeeded)
    {
        currentId = id;
        TSqlORMapper<UsersObject> mapper;
        user = Users(mapper.findByPrimaryKey(id));
    }
    return user;
}

Profiles Users::profile() const
{
    return Profiles::get(id());

}

bool Users::isOnline() const
{
    return isOnline(id());
}

bool Users::isAdmin() const
{
    return username() == "KOPOJI"; //This is hard! Don't hack me!)
}

bool Users::isOnline(const int& userId, bool updateNeeded) const
{
    static bool online = false;
    static int savedUserId = -1;

    if(savedUserId == -1 || updateNeeded || savedUserId != userId)
    {
        TSqlQuery query;
        query.prepare("SELECT COUNT(1) FROM `users` WHERE `id` = ? AND `updated_at` >= (NOW() - INTERVAL 15 MINUTE)");
        query.addBind(userId);
        query.exec();

        online = query.next() && query.value(0).toBool();
    }

    return online;
}

const Users &Users::getByIdentityKey(const QString& username, const bool updateNeeded)
{
    static Users user;
    if(user.isNull() || updateNeeded)
    {
        TSqlORMapper<UsersObject> mapper;
        TCriteria cri(UsersObject::Username, username);
        user = Users(mapper.findFirst(cri));
    }
    return user;
}

int Users::count()
{
    TSqlORMapper<UsersObject> mapper;
    return mapper.findCount();
}

QList<Users> Users::getAll()
{
    return tfGetModelListByCriteria<Users, UsersObject>();
}

QJsonArray Users::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<UsersObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<UsersObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Users(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Users::modelData()
{
    return d.data();
}

const TModelObject *Users::modelData() const
{
    return d.data();
}
