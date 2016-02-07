#ifndef USERSOBJECT_H
#define USERSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT UsersObject : public TSqlObject, public QSharedData
{
public:
    int id;
    QString username;
    QString email;
    QString encrypted_password;
    QString reset_password_token;
    QDateTime reset_password_sent_at;
    QDateTime remember_created_at;
    int sign_in_count;
    QDateTime current_sign_in_at;
    QDateTime last_sign_in_at;
    QString current_sign_in_ip;
    QString last_sign_in_ip;
    QString confirmation_token;
    QDateTime confirmed_at;
    QDateTime confirmation_sent_at;
    QString unconfirmed_email;
    int failed_attempts;
    QString unlock_token;
    QDateTime locked_at;
    QDateTime created_at;
    QDateTime updated_at;

    enum PropertyIndex {
        Id = 0,
        Username,
        Email,
        EncryptedPassword,
        ResetPasswordToken,
        ResetPasswordSentAt,
        RememberCreatedAt,
        SignInCount,
        CurrentSignInAt,
        LastSignInAt,
        CurrentSignInIp,
        LastSignInIp,
        ConfirmationToken,
        ConfirmedAt,
        ConfirmationSentAt,
        UnconfirmedEmail,
        FailedAttempts,
        UnlockToken,
        LockedAt,
        CreatedAt,
        UpdatedAt,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("users"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString username READ getusername WRITE setusername)
    T_DEFINE_PROPERTY(QString, username)
    Q_PROPERTY(QString email READ getemail WRITE setemail)
    T_DEFINE_PROPERTY(QString, email)
    Q_PROPERTY(QString encrypted_password READ getencrypted_password WRITE setencrypted_password)
    T_DEFINE_PROPERTY(QString, encrypted_password)
    Q_PROPERTY(QString reset_password_token READ getreset_password_token WRITE setreset_password_token)
    T_DEFINE_PROPERTY(QString, reset_password_token)
    Q_PROPERTY(QDateTime reset_password_sent_at READ getreset_password_sent_at WRITE setreset_password_sent_at)
    T_DEFINE_PROPERTY(QDateTime, reset_password_sent_at)
    Q_PROPERTY(QDateTime remember_created_at READ getremember_created_at WRITE setremember_created_at)
    T_DEFINE_PROPERTY(QDateTime, remember_created_at)
    Q_PROPERTY(int sign_in_count READ getsign_in_count WRITE setsign_in_count)
    T_DEFINE_PROPERTY(int, sign_in_count)
    Q_PROPERTY(QDateTime current_sign_in_at READ getcurrent_sign_in_at WRITE setcurrent_sign_in_at)
    T_DEFINE_PROPERTY(QDateTime, current_sign_in_at)
    Q_PROPERTY(QDateTime last_sign_in_at READ getlast_sign_in_at WRITE setlast_sign_in_at)
    T_DEFINE_PROPERTY(QDateTime, last_sign_in_at)
    Q_PROPERTY(QString current_sign_in_ip READ getcurrent_sign_in_ip WRITE setcurrent_sign_in_ip)
    T_DEFINE_PROPERTY(QString, current_sign_in_ip)
    Q_PROPERTY(QString last_sign_in_ip READ getlast_sign_in_ip WRITE setlast_sign_in_ip)
    T_DEFINE_PROPERTY(QString, last_sign_in_ip)
    Q_PROPERTY(QString confirmation_token READ getconfirmation_token WRITE setconfirmation_token)
    T_DEFINE_PROPERTY(QString, confirmation_token)
    Q_PROPERTY(QDateTime confirmed_at READ getconfirmed_at WRITE setconfirmed_at)
    T_DEFINE_PROPERTY(QDateTime, confirmed_at)
    Q_PROPERTY(QDateTime confirmation_sent_at READ getconfirmation_sent_at WRITE setconfirmation_sent_at)
    T_DEFINE_PROPERTY(QDateTime, confirmation_sent_at)
    Q_PROPERTY(QString unconfirmed_email READ getunconfirmed_email WRITE setunconfirmed_email)
    T_DEFINE_PROPERTY(QString, unconfirmed_email)
    Q_PROPERTY(int failed_attempts READ getfailed_attempts WRITE setfailed_attempts)
    T_DEFINE_PROPERTY(int, failed_attempts)
    Q_PROPERTY(QString unlock_token READ getunlock_token WRITE setunlock_token)
    T_DEFINE_PROPERTY(QString, unlock_token)
    Q_PROPERTY(QDateTime locked_at READ getlocked_at WRITE setlocked_at)
    T_DEFINE_PROPERTY(QDateTime, locked_at)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
};

#endif // USERSOBJECT_H
