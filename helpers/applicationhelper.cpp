#include "applicationhelper.h"

QString ApplicationHelper::paginationLinks(const int& pageNumber, const int& pagesCount, const QString& linkName, const int& show)
{
    QString links = "";

    if(pagesCount == 1)
        return links;

    if(pageNumber > 1)
    {
        links.append(
                    QString(
                        "<a class=\"first_page\" href=\"?%1=1\"> «« </a>"
                        "<a class=\"previous_page\" rel=\"prev\" href=\"?%1=%2\"> « </a>"
                        ).arg(linkName).arg(pageNumber - 1)
                    );
    }

    int start = pageNumber - show;
    if(start < 1)
        start = 1;
    int end = pageNumber + show;
    if(end > pagesCount)
        end = pagesCount;

    for(int i = start; i <= end; ++i)
    {
        if(pageNumber == i)
            links += QString("<em class=\"current\">%1</em>").arg(i);
        else
            links += QString("<a href=\"?%1=%2\">%2</a>").arg(linkName).arg(i);
    }

    if(pageNumber < pagesCount)
    {
        links.append(QString("<a class=\"next_page\" rel=\"next\" href=\"?%1=%2\"> » </a>"
                             "<a class=\"last_page\" href=\"?%1=%4\"> »» </a>").arg(linkName).arg(pageNumber + 1).arg(pagesCount));
    }
    return links;
}

QString ApplicationHelper::truncate(const QString& str, const int& size, const QString& separator)
{
    if(str.size() > size)
        return str.left(size) + separator;
    return str;
}
QUrl ApplicationHelper::createUrl(const QString& url, const QString& page)
{
    return createUrl(url, page.toInt());
}

QUrl ApplicationHelper::createUrl(const QStringList &urlParts, const QString& page)
{
    return createUrl(urlParts.join('/'), page);
}

QUrl ApplicationHelper::createUrl(const QString& url, const int& page)
{
    const QString urlSuffix = url.endsWith(".html") ? "" : ".html";
    const QString urlRoot = url.startsWith('/') ? "": "/";
    if(page < 2)
        return QUrl(urlRoot + url + urlSuffix);
    return QUrl(QString("%1%2%3?page=%4").arg(urlRoot, url, urlSuffix).arg(page));
}

QString ApplicationHelper::parseCode(const QString &code, bool getLangOnly)
{
    QFile f("./languages.txt");

    if(!f.open(QIODevice::ReadOnly))
        return code;
    QString languages = "";

    QTextStream in(&f);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        line.resize(line.indexOf(':'));
        line = line.trimmed();
        languages += line + '|';
    }
    f.close();

    if(languages.size())
        languages.resize(languages.length() - 1);
    languages = languages.toUpper();

    QString result = code;

    QRegExp rx("\\[(" + languages + ")\\](.*)\\[/\\1\\]", Qt::CaseInsensitive);
    rx.setMinimal(true);

    int s = -1;

    QString ret = "";

    while((s = rx.indexIn(result, s+1)) >= 0)
    {
        QString name = codeFile(rx.cap(1).trimmed().toUpper());
        if(getLangOnly)
            return rx.cap(1);

        ret += rx.cap(1);
        result.replace(rx.cap(0), QString("<h6><b>%1 %2</b></h6><pre class='editor' lang='%3'>%4</pre>").arg(
           H::tr("Code"), codeTitle(name).toHtmlEscaped(), name.toHtmlEscaped(), rx.cap(2).toHtmlEscaped()
        ));
        s+= rx.cap(0).length();
    }

    rx.setPattern("\\[img\\](https?://[^<>]+)\\[/img\\]");
    result.replace(rx, "<a href='\\1' rel='prettyPhoto[gallery]'><img src=\\1' class='attach'></a>");

    result.replace("\n", "<br>");


    const int BB_CODES_COUNT = 4;
    const QString classes[BB_CODES_COUNT] = {"bold", "cursive", "underline", "del"};
    const QString bb_codes[BB_CODES_COUNT] = {"b", "i", "u", "s"};

    for(int i = 0; i < BB_CODES_COUNT; ++i)
    {
        rx.setPattern("\\[" + bb_codes[i] + "\\](.*)\\[/" + bb_codes[i] + "\\]");
        result.replace(rx, "<span class='" + classes[i] + "'>\\1</span>");
    }


    return result;
}

QString ApplicationHelper::codeFile(const QString &tagName)
{
    QFile f("./languages.txt");
    if(!f.open(QIODevice::ReadOnly))
        return tagName;

    QTextStream in(&f);
    while(!in.atEnd())
    {
        QString line = in.readLine().trimmed();
        if(line.isEmpty())
            continue;
        QStringList words = line.left(line.indexOf(':')).trimmed().toUpper().split('|');
        line = line.mid(line.indexOf(':') + 1).trimmed();

        for(const auto& word: words)
            if(word == tagName)
                return line;
    }
    f.close();

    return "php";
}

QString ApplicationHelper::codeTitle(const QString &tagName)
{
    QFile f("./languages_titles.txt");
    if(!f.open(QIODevice::ReadOnly))
        return tagName;

    QTextStream in(&f);
    while(!in.atEnd())
    {
        QString line = in.readLine().trimmed();
        if(line.isEmpty())
            continue;
        QString word = line.left(line.indexOf(':')).trimmed();

        if(word == tagName)
            return line.mid(line.indexOf(':') + 1).trimmed();
    }

    f.close();

    return tagName;
}

QString ApplicationHelper::getFlash(const QMap<QString, QString>& flash)
{
    if(flash.empty())
        return "";
    QMap<QString, QString> classes;
    classes.insert("notice", "info");
    classes.insert("alert", "danger");
    classes.insert("success", "success");
    classes.insert("warning", "warning");

    QString result = "";

    for(const auto& msg: flash.toStdMap())
    {
        if(!classes.contains(msg.first) || msg.second.trimmed().isEmpty())
            continue;
        result += QString("<div class=\"alert alert-%1\">%2</div>\n").arg(classes[msg.first], msg.second);
    }
    return result;
}

QMap<QString, QString> ApplicationHelper::codesTitles()
{
    QFile f("./languages_titles.txt");
    if(!f.open(QIODevice::ReadOnly))
        return QMap<QString, QString>();

    QMap<QString, QString> result;

    QTextStream in(&f);
    while(!in.atEnd())
    {
        QString line = in.readLine().trimmed();
        if(line.isEmpty())
            continue;
        QStringList tag = line.trimmed().split(": ");
        result[tag[1].trimmed()] = tag[0].trimmed();
    }

    f.close();

    return result;
}

QString ApplicationHelper::userStatusImage(const bool& isOnline)
{
    return QString("<img src=\"/images/user_%1line.gif\">").arg(isOnline ? "on" : "off");
}

QString ApplicationHelper::language(const bool &updateNeeded)
{
    static QString lang;

    if(lang.isEmpty() || updateNeeded)
    {
        QFile file("./translations/tr_language.txt");

        if(!file.open(QIODevice::ReadOnly))
            return "en";

        lang = file.readAll().trimmed();

        file.close();
    }
    return lang;
}

QString ApplicationHelper::tr(const char *sourceText, const char *disambiguation, int n)
{
    static QTranslator translator;
    static QString lang = language();

    if(translator.isEmpty() || lang != language())
    {
        lang = language();
        if(!translator.load(language(), "./translations/"))
            return sourceText;
    }

    return translator.translate("H", sourceText, disambiguation, n);
}

QString ApplicationHelper::imageResize(const QString& imagePath, const QString& imageType, const int &MAX_WIDTH, const int &MAX_HEIGHT, const bool &isAvatar)
{
    //generate new image name
    const QString& hash = QCryptographicHash::hash(std::to_string(QDateTime::currentMSecsSinceEpoch()).c_str(), QCryptographicHash::Sha256).toHex();
    const QString& dir = QString("./public/images/%1/").arg(isAvatar ? "avatars" : "uploads");
    const QString& newImageName = QString("image%1.%2").arg(hash).arg(imageType.toLower());

    //min size of image to scale
    const int MIN_WIDTH = 150;
    const int MIN_HEIGHT = 150;


    //open image
    QImage img(imagePath, imageType.toStdString().c_str());

    //scale image if needed
    if(img.width() >= MAX_WIDTH || img.height() >= MAX_HEIGHT)
        img = img.scaled(MAX_WIDTH, MAX_HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    if(img.width() <= MIN_WIDTH || img.height() <= MIN_HEIGHT)
        img = img.scaled(MIN_WIDTH, MIN_HEIGHT, Qt::IgnoreAspectRatio, Qt::FastTransformation);


    //create file
    QFile file(dir + newImageName);
    file.open(QIODevice::WriteOnly);

    //save image
    bool saved = img.save(&file, imageType.toStdString().c_str());

    file.close();
    return saved ? newImageName : QString();
}

QString ApplicationHelper::specifiedClass(const QString &value)
{
    return value.trimmed().isEmpty() ? " class='not_specified'" : "";
}
QString ApplicationHelper::specifiedText(const QString &value, const QString &returnValue)
{
    return value.trimmed().isEmpty() ? "not_specified" : (returnValue.isEmpty() ? value : returnValue);
}

bool ApplicationHelper::imageExists(const QString &path)
{
    QFileInfo checkFile("./public/images/" + path);
    return checkFile.exists() && checkFile.isFile();
}

QString ApplicationHelper::cycle(const QStringList& values)
{
    if(values.empty())
        return "";

    static QStringListIterator it = values;

    if(it.hasNext())
        return it.next();
    it.toFront();
    return it.next();
}
