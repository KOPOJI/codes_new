#ifndef APPLICATIONHELPER_H
#define APPLICATIONHELPER_H

#include <TGlobal>
#include <QUrl>
#include <QStringList>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>

#include <TWebApplication>
#include <QTranslator>

#include <QCryptographicHash>
#include <QDateTime>
#include <QImage>

#include <Magick++.h>

#include <QRegularExpression>

#include <QBuffer>

class T_HELPER_EXPORT ApplicationHelper
{
public:

    static QString paginationLinks(const int& pageNumber, const int& pagesCount, const QString& linkName = "page", const int& show = 3);
    static QString truncate(const QString& str, const int& size, const QString &separator = "..");
    static QUrl createUrl(const QString& url, const int& page = 1);
    static QUrl createUrl(const QString& url, const QString& page);
    static QUrl createUrl(const QStringList &urlParts, const QString& page = "1");

    static QString parseCode(const QString& code, const bool& getLangOnly = false, const bool& parseQuotes = true);
    static QString codeFile(const QString& tagName);
    static QString codeTitle(const QString& tagName);

    static QString getFlash(const QMap<QString, QString> &flash);

    static QMap<QString, QString> codesTitles();

    static QString userStatusImage(const bool& isOnline);

    static QString tr(const char * sourceText, const char * disambiguation = 0, int n = -1);

    static QString language(const bool& updateNeeded = false);

    static QString imageResize(const QString &imagePath, const QString &imageType, const int& width = 1280, const int& MAX_HEIGHT = 960, const bool& isAvatar = false);

    static QString specifiedClass(const QString& value);
    static QString specifiedText(const QString& value, const QString& returnValue = QString());

    static bool imageExists(const QString& path);
    static bool fileExists(const QString& path);

    static QString cycle(const QStringList& values);

    static QString getCaptchaCode(const int &length = 7);

    static QByteArray getCaptcha(const QString& text = getCaptchaCode(), const int& width = 150, const int& height = 50);
};

typedef ApplicationHelper H;

#endif // APPLICATIONHELPER_H
