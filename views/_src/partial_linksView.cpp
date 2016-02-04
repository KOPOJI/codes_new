#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h" 
#include "privatemessages.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_linksView : public TActionView
{
  Q_OBJECT
public:
  partial_linksView() : TActionView() { }
  partial_linksView(const partial_linksView &) : TActionView() { }
  QString toString();
};

QString partial_linksView::toString()
{
  responsebody.reserve(5336);
    responsebody += tr("<div class=\"navbar navbar-fluid-top navbar-inverse\">\n  <div class=\"navbar-inner\">\n    <div class=\"container-fluid\">\n\n      ");
  responsebody += QVariant(linkTo("SaveCode.RU", H::createUrl("/"), Tf::Get, "", a("class", "navbar-brand"))).toString();
  responsebody += tr("\n\n      <div class=\"container-fluid nav-collapse\" role=\"navigation\">\n\n        <ul class=\"nav navbar-nav\" aria-labelledby=\"dLabel\">\n\n          <li class=\"dropdown\">\n            <a href=\"#\" class=\"dropdown-toggle\" data-toggle=\"dropdown\">");
  responsebody += THttpUtility::htmlEscape(H::tr("Codes"));
  responsebody += tr(" <b class=\"caret\"></b></a>\n            <ul class=\"dropdown-menu\">\n              <li>");
  responsebody += QVariant(linkTo(H::tr("Insert code"), H::createUrl({"codes", "new"}))).toString();
  responsebody += tr("</li>\n              ");
  if(QString(httpRequest().header().path()).contains(QRegExp("codes/\\d+\\.html", Qt::CaseInsensitive))) {;
  responsebody += tr("              <li>\n                ");
  responsebody += QVariant(linkTo(H::tr("Edit code"), QUrl(QString(httpRequest().header().path()).replace(".html", "/edit.html")))).toString();
  responsebody += tr("\n              </li>\n              ");
  };
  responsebody += tr("            </ul>\n          </li>\n\n          <li class=\"dropdown\">\n            <a href=\"#\" class=\"dropdown-toggle\" data-toggle=\"dropdown\">");
  responsebody += THttpUtility::htmlEscape(H::tr("Pictures"));
  responsebody += tr(" <b class=\"caret\"></b></a>\n            <ul class=\"dropdown-menu\">\n                <li>");
  responsebody += QVariant(linkTo(H::tr("Listing pictures"), H::createUrl("attachments", 1))).toString();
  responsebody += tr("</li>\n                  <li>");
  responsebody += QVariant(linkTo(H::tr("Upload picture"), H::createUrl({"attachments", "new"}))).toString();
  responsebody += tr("</li>\n            </ul>\n          </li>\n\n          <li class=\"dropdown\">\n            <a href=\"#\" class=\"dropdown-toggle\" data-toggle=\"dropdown\">");
  responsebody += THttpUtility::htmlEscape(H::tr("Users"));
  responsebody += tr(" <b class=\"caret\"></b></a>\n            <ul class=\"dropdown-menu\">\n              <li>");
  responsebody += QVariant(linkTo(H::tr("Listing users"), H::createUrl("users", 1))).toString();
  responsebody += tr("</li>\n              ");
  if(controller()->isUserLoggedIn()) {;
    responsebody += tr("              ");
  tfetch(Users, user);
  responsebody += tr("                 <li>");
  responsebody += QVariant(linkTo(H::tr("Profile"), H::createUrl({"user", "profile"}))).toString();
  responsebody += tr("</li>\n                 <li>");
  responsebody += QVariant(linkTo(QString("%1 (%2)").arg(H::tr("Private Messages")).arg(QString::number(PrivateMessages::count(user.id()))), H::createUrl({"pm", "inbox"}))).toString();
  responsebody += tr("</li>\n                 <li>");
  responsebody += QVariant(linkTo(H::tr("Log out"), H::createUrl({"user", "logout"}), Tf::Delete)).toString();
  responsebody += tr("</li>\n              ");
  } else {;
  responsebody += tr("              <li>");
  responsebody += QVariant(linkTo(H::tr("Sign"), H::createUrl({"user", "login"}))).toString();
  responsebody += tr("</li>\n                  <li>");
  responsebody += QVariant(linkTo(H::tr("Sign up"), H::createUrl({"user", "register"}))).toString();
  responsebody += tr("</li>\n              ");
  };
  responsebody += tr("            </ul>\n          </li>\n\n          ");
  if (false && controller()->isUserLoggedIn()) {;
  responsebody += tr("            <li>");
  responsebody += QVariant(linkTo(H::tr("Chat"), H::createUrl("show_hide_chat", 1), Tf::Get, "", a("class", "chat"))).toString();
  responsebody += tr("</li>\n          ");
  };
  responsebody += tr("\n          <li class=\"dropdown\">\n            <a href=\"#\" class=\"dropdown-toggle\" data-toggle=\"dropdown\">");
  responsebody += THttpUtility::htmlEscape(H::tr("Language"));
  responsebody += tr(" <b class=\"caret\"></b></a>\n            <ul class=\"dropdown-menu\">\n              <li>\n                ");
  responsebody += QVariant(linkTo(imageTag(imagePath("flag_russian.gif"), a("alt", "Русский язык")) + " Русский",
                            H::createUrl("/language/russian"), Tf::Get, "", a("alt", "Русский язык") | a("title", "Русский язык"))).toString();
  responsebody += tr("\n              </li>\n              <li>\n                ");
  responsebody += QVariant(linkTo(imageTag(imagePath("flag_english.gif"), a("alt", "English")) + " English",
                            H::createUrl("/language/english"), Tf::Get, "", a("alt", "English") | a("title", "English"))).toString();
  responsebody += tr("\n              </li>\n            </ul>\n          </li>\n\n      ");
  if(false && controller()->isUserLoggedIn() /* && current_user.admin*/) {;
  responsebody += tr("          <li>\n    ");
  /*== linkTo(" X ", H::createUrl({"codes", "show_delete_links"}), style: "color:red") */
  responsebody += tr("          </li>\n          <li>\n    ");
  /*== linkTo(" X ([a;b]) ", H::createUrl({"codes", "delete_interval"}), style: "color:red") */
  responsebody += tr("          </li>\n      ");
  };
  responsebody += tr("        </ul>\n      </div>\n    </div>\n  </div>\n</div>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(partial_linksView)
T_REGISTER_VIEW(partial_linksView)

#include "partial_linksView.moc"
