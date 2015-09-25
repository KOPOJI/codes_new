#include <QtCore>
#include <TreeFrogView>
#include "attachments.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT attachments_showView : public TActionView
{
  Q_OBJECT
public:
  attachments_showView() : TActionView() { }
  attachments_showView(const attachments_showView &) : TActionView() { }
  QString toString();
};

QString attachments_showView::toString()
{
  responsebody.reserve(1449);
    responsebody += tr("\n");
  tfetch(Attachments, attachments);
  responsebody += tr("\n");
  if(!attachments.code().isNull()) {;
  responsebody += tr("    <p>\n      <strong>");
  responsebody += THttpUtility::htmlEscape(H::tr("Code"));
  responsebody += tr(":</strong>\n        ");
  responsebody += QVariant(linkTo(H::truncate(attachments.code().title(), 20), H::createUrl({"codes", QString::number(attachments.code().id())}), Tf::Get, a("class", "link"))).toString();
  responsebody += tr("\n    </p>\n");
  };
  responsebody += tr("<p>\n  <strong>");
  responsebody += THttpUtility::htmlEscape(H::tr("Image"));
  responsebody += tr(":</strong>\n    ");
  responsebody += QVariant(linkTo(H::truncate(attachments.image(), 20), QUrl("/uploads/images/" + attachments.image()), Tf::Get, a("class", "link") | a("target", "_blank"))).toString();
  responsebody += tr("\n<br>\n<br>\n      <a href=\"/images/uploads/");
  responsebody += THttpUtility::htmlEscape(attachments.image());
  responsebody += tr("\" rel=\"prettyPhoto[gallery]\">\n          ");
  responsebody += QVariant(imageTag("/images/uploads/" + attachments.image(), a("class", "attach"))).toString();
  responsebody += tr("\n      </a>\n</p>\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", attachments.id()))).toString();
  responsebody += tr(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += tr("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(attachments_showView)
T_REGISTER_VIEW(attachments_showView)

#include "attachments_showView.moc"
