#ifndef USERS_H
#define USERS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractUser>
#include <TAbstractModel>

#include <botan/bcrypt.h>

#include "applicationhelper.h"

#include <TSqlQuery>

#include "profiles.h"
class TModelObject;
class UsersObject;
class QJsonArray;


class T_MODEL_EXPORT Users : public TAbstractUser, public TAbstractModel
{
public:
    Users();
    Users(const Users &other);
    Users(const UsersObject &object);
    ~Users();

    int id() const;
    QString username() const;
    void setUsername(const QString &username);
    QString email() const;
    void setEmail(const QString &email);
    QString encryptedPassword() const;
    void setEncryptedPassword(const QString &encryptedPassword);
    QString resetPasswordToken() const;
    void setResetPasswordToken(const QString &resetPasswordToken);
    QDateTime resetPasswordSentAt() const;
    void setResetPasswordSentAt(const QDateTime &resetPasswordSentAt);
    QDateTime rememberCreatedAt() const;
    void setRememberCreatedAt(const QDateTime &rememberCreatedAt);
    int signInCount() const;
    void setSignInCount(int signInCount);
    QDateTime currentSignInAt() const;
    void setCurrentSignInAt(const QDateTime &currentSignInAt);
    QDateTime lastSignInAt() const;
    void setLastSignInAt(const QDateTime &lastSignInAt);
    QString currentSignInIp() const;
    void setCurrentSignInIp(const QString &currentSignInIp);
    QString lastSignInIp() const;
    void setLastSignInIp(const QString &lastSignInIp);
    QString confirmationToken() const;
    void setConfirmationToken(const QString &confirmationToken);
    QDateTime confirmedAt() const;
    void setConfirmedAt(const QDateTime &confirmedAt);
    QDateTime confirmationSentAt() const;
    void setConfirmationSentAt(const QDateTime &confirmationSentAt);
    QString unconfirmedEmail() const;
    void setUnconfirmedEmail(const QString &unconfirmedEmail);
    int failedAttempts() const;
    void setFailedAttempts(int failedAttempts);
    QString unlockToken() const;
    void setUnlockToken(const QString &unlockToken);
    QDateTime lockedAt() const;
    void setLockedAt(const QDateTime &lockedAt);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    void setUpdatedAt(const QDateTime &updatedAt);
    QString identityKey() const { return username(); }
    Users &operator=(const Users &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    Profiles profile() const;
    bool isAdmin() const;
    bool isOnline() const;
    bool isOnline(const int& userId) const;
    static Users authenticate(const QString &email, const QString &password);
    static Users create(const QString &username, const QString &email, const QString &encryptedPassword, const QString &resetPasswordToken, const QDateTime &resetPasswordSentAt, const QDateTime &rememberCreatedAt, int signInCount, const QDateTime &currentSignInAt, const QDateTime &lastSignInAt, const QString &currentSignInIp, const QString &lastSignInIp, const QString &confirmationToken, const QDateTime &confirmedAt, const QDateTime &confirmationSentAt, const QString &unconfirmedEmail, int failedAttempts, const QString &unlockToken, const QDateTime &lockedAt);
    static Users create(const QVariantMap &values);
    static Users get(int id);

    static Users getByIdentityKey(const QString& username);

    static int count();
    static QList<Users> getAll();
    static QJsonArray getAllJson();


private:
    QSharedDataPointer<UsersObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Users)
Q_DECLARE_METATYPE(QList<Users>)

#endif // USERS_H
