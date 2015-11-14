#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_private_messages_linksView : public TActionView
{
  Q_OBJECT
public:
  partial_private_messages_linksView() : TActionView() { }
  partial_private_messages_linksView(const partial_private_messages_linksView &) : TActionView() { }
  QString toString();
};

QString partial_private_messages_linksView::toString()
{
  responsebody.reserve(751);
  responsebody += tr("<div class=\"span7\">\n  ");
  responsebody += THttpUtility::htmlEscape(H::tr("Go to"));
  responsebody += tr(" ");
  responsebody += QVariant(linkTo(H::tr("inbox"), H::createUrl({"pm", "inbox"}), Tf::Get, a("class", "link"))).toString();
  responsebody += tr("\n  |\n  ");
  responsebody += QVariant(linkTo(H::tr("outbox"), H::createUrl({"pm", "outbox"}), Tf::Get, a("class", "link"))).toString();
  responsebody += tr("\n  <br>\n  ");
  responsebody += THttpUtility::htmlEscape(H::tr("Or"));
  responsebody += tr("\n  ");
  responsebody += QVariant(linkTo(H::tr("New Private message"), H::createUrl({"pm", "new"}), Tf::Get, a("class", "link"))).toString();
  responsebody += tr("\n</div>\n<div style=\"clear:both\"></div>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(partial_private_messages_linksView)
T_REGISTER_VIEW(partial_private_messages_linksView)

#include "partial_private_messages_linksView.moc"
