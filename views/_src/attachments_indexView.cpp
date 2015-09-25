#include <QtCore>
#include <TreeFrogView>
#include "attachments.h" 
#include "users.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT attachments_indexView : public TActionView
{
  Q_OBJECT
public:
  attachments_indexView() : TActionView() { }
  attachments_indexView(const attachments_indexView &) : TActionView() { }
  QString toString();
};

QString attachments_indexView::toString()
{
  responsebody.reserve(2069);
      responsebody += tr("<h1>");
  responsebody += THttpUtility::htmlEscape(H::tr("Listing pictures"));
  responsebody += tr("</h1>\n\n");
  tfetch(QList<Attachments>, attachmentsList);
  responsebody += tr("\n\n");
  if(attachmentsList.isEmpty()) {;
  responsebody += tr("    ");
  responsebody += THttpUtility::htmlEscape(H::tr("no_pictures"));
  responsebody += tr("\n");
  } else {;
  responsebody += tr("    <div class=\"attachchments\">\n        ");
  for (const auto &attachment : attachmentsList) {;
  responsebody += tr("\n            <div class=\"attach_item\">\n\n                ");
  if(attachment.codeId()) {;
  responsebody += tr("                    ");
  responsebody += QVariant(linkTo(H::tr("View code"), H::createUrl({"codes", QString::number(attachment.code().id())}), Tf::Get, a("class", "link"))).toString();
  responsebody += tr("\n                ");
  };
  responsebody += tr("\n                <a href=\"/images/uploads/");
  responsebody += THttpUtility::htmlEscape(attachment.image());
  responsebody += tr("\" rel=\"prettyPhoto[gallery]\">\n                    ");
  responsebody += QVariant(imageTag("/images/uploads/" + attachment.image(), a("class", "attach"))).toString();
  responsebody += tr("\n                </a>\n\n                ");
  responsebody += QVariant(linkTo(H::tr("Edit"), H::createUrl({"attachments", QString::number(attachment.id()), "edit"}), Tf::Get, a("class", "link"))).toString();
  responsebody += tr("\n                ");
  tfetch(Users, user);
  responsebody += tr("        ");
  if(attachment.canBeDeleted(user)) {;
  responsebody += tr("                ");
  responsebody += QVariant(linkTo(H::tr("Destroy"),
                    H::createUrl({"attachments", QString::number(attachment.id()), "remove"}),
                    Tf::Post,
                    QString("confirm('%1')").arg(H::tr("Are you sure?")),
                    a("class", "link"))).toString();
  responsebody += tr("\n        ");
  };
  responsebody += tr("            </div>\n        ");
  };
  responsebody += tr("    </div>\n");
  };

  return responsebody;
}

Q_DECLARE_METATYPE(attachments_indexView)
T_REGISTER_VIEW(attachments_indexView)

#include "attachments_indexView.moc"
