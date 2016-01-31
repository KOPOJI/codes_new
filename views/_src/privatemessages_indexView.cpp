#include <QtCore>
#include <TreeFrogView>
#include "privatemessages.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT privatemessages_indexView : public TActionView
{
  Q_OBJECT
public:
  privatemessages_indexView() : TActionView() { }
  privatemessages_indexView(const privatemessages_indexView &) : TActionView() { }
  QString toString();
};

QString privatemessages_indexView::toString()
{
  responsebody.reserve(2743);
    responsebody += tr("\n");
  responsebody += QVariant(renderPartial("private_messages_links")).toString();
  responsebody += tr("\n\n");
  tfetch(QList<PrivateMessages>, privateMessagesList); tfetch(QString, action);
  for(auto& message: privateMessagesList) {;
  responsebody += tr("<div class=\"private_message span9\" style=\"background-color:");
  responsebody += THttpUtility::htmlEscape(H::cycle({"#f9f9f9", "#f7f7f7"}));
  responsebody += tr("\">\n          <h4 style=\"margin-bottom: -15px;margin-top:3px;font-weight:");
  responsebody += THttpUtility::htmlEscape(message.read() ? "normal" : "bold");
  responsebody += tr("\">\n\n            ");
  responsebody += QVariant(linkTo(message.title(), H::createUrl({"pm", action, QString::number(message.id())}), Tf::Get, a("class", "link"))).toString();
  responsebody += tr("\n            <small>\n              ");
  if(action == "outbox") {;
  responsebody += tr("                  ");
  responsebody += THttpUtility::htmlEscape(H::tr("To"));
  responsebody += tr("\n                  <span");
  responsebody += THttpUtility::htmlEscape(H::specifiedClass(message.userTo().username()));
  responsebody += tr(">\n                    ");
  responsebody += QVariant(H::specifiedText(message.userTo().username(), linkTo(message.userTo().username(), H::createUrl({"user", QString::number(message.userTo().id())}), Tf::Get, a("class", "link")))).toString();
  responsebody += tr("\n                  </span>\n              ");
  } else {;
  responsebody += tr("                  ");
  responsebody += THttpUtility::htmlEscape(H::tr("From"));
  responsebody += tr("\n                  <span");
  responsebody += THttpUtility::htmlEscape(H::specifiedClass(message.userFrom().username()));
  responsebody += tr(">\n                    ");
  responsebody += QVariant(H::specifiedText(message.userFrom().username(), linkTo(message.userFrom().username(), H::createUrl({"user", QString::number(message.userFrom().id())}), Tf::Get, a("class", "link")))).toString();
  responsebody += tr("\n                  </span>\n              ");
  };
  responsebody += tr("            </small>\n          </h4>\n          <br>\n          ");
  responsebody += THttpUtility::htmlEscape(H::truncate(message.text(), 50));
  responsebody += tr("\n          <div style=\"float: right\">\n    ");
  responsebody += QVariant(linkTo(H::tr("Show"), H::createUrl({"pm", action, QString::number(message.id())}))).toString();
  responsebody += tr("\n            |\n    ");
  responsebody += QVariant(linkTo(H::tr("Destroy"), H::createUrl({"pm", QString::number(message.id()), "remove"}), Tf::Get, "confirm (" + H::tr("Are you sure?") + ")")).toString();
  responsebody += tr("\n          </div>\n        </div>\n");
  };

  return responsebody;
}

Q_DECLARE_METATYPE(privatemessages_indexView)
T_REGISTER_VIEW(privatemessages_indexView)

#include "privatemessages_indexView.moc"
