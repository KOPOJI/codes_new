#include <QtCore>
#include <TreeFrogView>
#include "privatemessages.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT privatemessages_showView : public TActionView
{
  Q_OBJECT
public:
  privatemessages_showView() : TActionView() { }
  privatemessages_showView(const privatemessages_showView &) : TActionView() { }
  QString toString();
};

QString privatemessages_showView::toString()
{
  responsebody.reserve(2400);
  responsebody += tr("<!DOCTYPE html>\n");
    tfetch(PrivateMessages, privateMessages);
  responsebody += tr("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += tr("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += tr("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += tr("</p>\n\n<h1>Showing Private Messages</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(privateMessages.id());
  responsebody += tr("</dd><br />\n<dt>User from ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(privateMessages.userFromId());
  responsebody += tr("</dd><br />\n<dt>User to ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(privateMessages.userToId());
  responsebody += tr("</dd><br />\n<dt>Title</dt><dd>");
  responsebody += THttpUtility::htmlEscape(privateMessages.title());
  responsebody += tr("</dd><br />\n<dt>Text</dt><dd>");
  responsebody += THttpUtility::htmlEscape(privateMessages.text());
  responsebody += tr("</dd><br />\n<dt>File</dt><dd>");
  responsebody += THttpUtility::htmlEscape(privateMessages.file());
  responsebody += tr("</dd><br />\n<dt>Deleted by from User</dt><dd>");
  responsebody += THttpUtility::htmlEscape(privateMessages.deletedByFromUser());
  responsebody += tr("</dd><br />\n<dt>Deleted by to User</dt><dd>");
  responsebody += THttpUtility::htmlEscape(privateMessages.deletedByToUser());
  responsebody += tr("</dd><br />\n<dt>Read</dt><dd>");
  responsebody += THttpUtility::htmlEscape(privateMessages.read());
  responsebody += tr("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(privateMessages.createdAt());
  responsebody += tr("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(privateMessages.updatedAt());
  responsebody += tr("</dd><br />\n<dt>To Message ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(privateMessages.toMessageId());
  responsebody += tr("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", privateMessages.id()))).toString();
  responsebody += tr(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += tr("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(privatemessages_showView)
T_REGISTER_VIEW(privatemessages_showView)

#include "privatemessages_showView.moc"
