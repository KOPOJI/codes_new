#include <QtCore>
#include <TreeFrogView>
#include "codes.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT layouts_applicationView : public TActionView
{
  Q_OBJECT
public:
  layouts_applicationView() : TActionView() { }
  layouts_applicationView(const layouts_applicationView &) : TActionView() { }
  QString toString();
};

QString layouts_applicationView::toString()
{
  responsebody.reserve(5015);
    responsebody += tr("<!DOCTYPE html>\n<html lang=\"ru\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta http-equiv=\"X-UA-Compatible\" content=\"IE=Edge,chrome=1\">\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n  <meta name=\"keywords\" content=\"заметка, добавить заметку, pastebin, загрузка картинок\">\n  <meta name=\"description\" content=\"SaveCode.RU - это сайт, где Вы можете сохранить любой текст с картинками или без них, без регистрации и навязчивой рекламы.\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += tr("</title>\n  <!--[if lt IE 9]>\n  <script src=\"//cdnjs.cloudflare.com/ajax/libs/html5shiv/3.6.1/html5shiv.js\" type=\"text/javascript\"></script>\n  <![endif]-->\n  ");
  responsebody += QVariant(styleSheetTag("application.css", a("media", "all") | a("data-turbolinks-track", "true") | a("rel", "stylesheet"))).toString();
  responsebody += tr("\n  ");
  responsebody += QVariant(styleSheetTag("styles.css", a("media", "all") | a("data-turbolinks-track", "true") | a("rel", "stylesheet"))).toString();
  responsebody += tr("\n  ");
  responsebody += QVariant(styleSheetTag("/images/apple-touch-icon-144x144-precomposed.png", a("sizes", "144x144") | a("type", "image/png") | a("rel", "apple-touch-icon-precomposed"))).toString();
  responsebody += tr("\n  ");
  responsebody += QVariant(styleSheetTag("/images/apple-touch-icon-114x114-precomposed.png", a("sizes", "114x114") | a("type", "image/png") | a("rel", "apple-touch-icon-precomposed"))).toString();
  responsebody += tr("\n  ");
  responsebody += QVariant(styleSheetTag("/images/apple-touch-icon-precomposed.png", a("type", "image/png") | a("rel", "apple-touch-icon-precomposed"))).toString();
  responsebody += tr("\n  ");
  responsebody += QVariant(styleSheetTag("/images/favicon.ico", a("type", "image/vnd.microsoft.icon") | a("rel", "shortcut icon"))).toString();
  responsebody += tr("\n    <script data-turbolinks-track=\"true\" src=\"/js/jquery-2.1.4.min.js\" charset=\"utf-8\" type=\"text/javascript\"></script>\n    <script data-turbolinks-track=\"true\" src=\"/js/application.js\" charset=\"utf-8\" type=\"text/javascript\"></script>\n    <script data-turbolinks-track=\"true\" src=\"/js/bbcodes.js\" charset=\"utf-8\" type=\"text/javascript\"></script>\n    <script data-turbolinks-track=\"true\" src=\"/js/prettyPhoto.js\" charset=\"utf-8\" type=\"text/javascript\"></script>\n    <script src=\"/ace/src-min-noconflict/ace.js\" type=\"text/javascript\" charset=\"utf-8\"></script>\n</head>\n<body>\n");
  responsebody += QVariant(renderPartial("links")).toString();
  responsebody += tr("\n\n<div class=\"container-fluid\">\n  <div class=\"row-fluid\">\n  <div class=\"col-md-2\" style=\"width: 250px;display: inline-block\">\n    <div class=\"well sidebar-nav\">\n      <ul class=\"nav nav-list\">\n        <li class=\"nav-header\">");
  responsebody += THttpUtility::htmlEscape(H::tr("Listing codes") + QString(" (%1)").arg(Codes::count()));
  responsebody += tr("</li>\n          ");
  auto codesList = Codes::getAll(httpRequest().queryItemValue("page", "1").toInt());
          if(codesList.empty())
          {
            renderPartial("error", QVariantMap({{"error", QVariant("Page not found")}}));
          }
          else
          {
              for(const auto& code: codesList) {;
  responsebody += tr("                ");
  QString uri = QString(httpRequest().header().path());
  responsebody += tr("        <li");
  responsebody += QVariant(uri.contains( QRegExp(QString("/codes/(?:%1|%2).html").arg(code.id()).arg(code.codeUrl()), Qt::CaseInsensitive) ) ? " class=\"current\"" : "").toString();
  responsebody += tr(">\n            ");
  responsebody += QVariant(linkTo(H::truncate(code.title(), 18), H::createUrl({"codes", QString::number(code.id())}, httpRequest().queryItemValue("page", "1")))).toString();
  responsebody += tr("\n        </li>\n               ");
  }
           };
  responsebody += tr("   </ul>\n       <div class=\"apple_pagination\">\n         ");
  responsebody += QVariant(H::paginationLinks(httpRequest().queryItemValue("page", "1").toInt(), Codes::pagesCount())).toString();
  responsebody += tr("\n       </div>\n     </div>\n   </div>\n    <div class=\"col-md-8\" style=\"min-width: 650px;display: inline-block\">\n\n\n");
  tfetch(QString, notice);
  tfetch(QString, error);
  tfetch(QString, warning);
  tfetch(QString, success);
  QMap<QString, QString> flashes;
flashes.insert("notice", notice);
flashes.insert("alert", error);
flashes.insert("success", success);
flashes.insert("warning", warning);
  responsebody += QVariant(H::getFlash(flashes)).toString();
  responsebody += tr("\n\n      ");
  responsebody += QVariant(yield()).toString();
  responsebody += tr("\n    </div>\n  </div>\n</div>\n\n<footer class=\"navbar-fixed-bottom\">\n  <div class=\"container\">\n    Just for fun. Just for save.\n  </div>\n</footer>\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(layouts_applicationView)
T_REGISTER_VIEW(layouts_applicationView)

#include "layouts_applicationView.moc"
