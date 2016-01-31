#include <QtCore>
#include <TreeFrogView>
#include "privatemessages.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT privatemessages_entryView : public TActionView
{
  Q_OBJECT
public:
  privatemessages_entryView() : TActionView() { }
  privatemessages_entryView(const privatemessages_entryView &) : TActionView() { }
  QString toString();
};

QString privatemessages_entryView::toString()
{
  responsebody.reserve(2711);
  responsebody += tr("<!DOCTYPE html>\n");
    tfetch(QVariantMap, privateMessages);
  responsebody += tr("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += tr("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += tr("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += tr("</p>\n\n<h1>New Private Messages</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += tr("\n  <p>\n    <label>User from ID<br /><input name=\"privateMessages[userFromId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(privateMessages["userFromId"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <label>User to ID<br /><input name=\"privateMessages[userToId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(privateMessages["userToId"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <label>Title<br /><input name=\"privateMessages[title]\" value=\"");
  responsebody += THttpUtility::htmlEscape(privateMessages["title"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <label>Text<br /><input name=\"privateMessages[text]\" value=\"");
  responsebody += THttpUtility::htmlEscape(privateMessages["text"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <label>File<br /><input name=\"privateMessages[file]\" value=\"");
  responsebody += THttpUtility::htmlEscape(privateMessages["file"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <label>Deleted by from User<br /><input name=\"privateMessages[deletedByFromUser]\" value=\"");
  responsebody += THttpUtility::htmlEscape(privateMessages["deletedByFromUser"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <label>Deleted by to User<br /><input name=\"privateMessages[deletedByToUser]\" value=\"");
  responsebody += THttpUtility::htmlEscape(privateMessages["deletedByToUser"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <label>Read<br /><input name=\"privateMessages[read]\" value=\"");
  responsebody += THttpUtility::htmlEscape(privateMessages["read"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <label>To Message ID<br /><input name=\"privateMessages[toMessageId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(privateMessages["toMessageId"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += tr("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(privatemessages_entryView)
T_REGISTER_VIEW(privatemessages_entryView)

#include "privatemessages_entryView.moc"
