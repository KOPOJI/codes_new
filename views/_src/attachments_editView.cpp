#include <QtCore>
#include <TreeFrogView>
#include "attachments.h" 
#include "codes.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT attachments_editView : public TActionView
{
  Q_OBJECT
public:
  attachments_editView() : TActionView() { }
  attachments_editView(const attachments_editView &) : TActionView() { }
  QString toString();
};

QString attachments_editView::toString()
{
  responsebody.reserve(1955);
      tfetch(QVariantMap, attachments);
  tfetch(Codes, attachCode);
  responsebody += tr("\n<h1>");
  responsebody += THttpUtility::htmlEscape(H::tr("Edit picture"));
  responsebody += tr("</h1>\n\n");
  responsebody += QVariant(formTag(H::createUrl({"attachments", attachments["id"].toString(), "save"}), Tf::Post, true)).toString();
  responsebody += tr("\n        <div class=\"form-inputs\">\n");
  auto codesList = Codes::getAll();
        const int& id = attachCode.isNull() ? 0 : attachCode.id();
if(!codesList.isEmpty()) {;
  responsebody += tr("        <label>");
  responsebody += THttpUtility::htmlEscape(H::tr("Code"));
  responsebody += tr("</label><br>\n        <select name=\"attachments[codeId]\">\n            <option value=\"\"></option>\n            ");
  for(const auto& code: codesList) {;
  responsebody += tr("                <option value=\"");
  responsebody += THttpUtility::htmlEscape(code.id());
  responsebody += tr("\"");
  if(code.id() == id) {;
  responsebody += tr("selected");
  };
  responsebody += tr(">");
  responsebody += THttpUtility::htmlEscape(code.title());
  responsebody += tr("</option>\n            ");
  };
  responsebody += tr("        </select>\n       ");
  };
  responsebody += tr("        <br>\n        <small><i>");
  responsebody += THttpUtility::htmlEscape(H::tr("Note: If picture less than 150x150, it will be resized to it"));
  responsebody += tr("</i></small><br>\n        <label>");
  responsebody += THttpUtility::htmlEscape(H::tr("Image"));
  responsebody += tr("</label><br>\n<input type=\"file\" name=\"attachments[image]\">\n            </div>\n        <div class=\"form-actions\">\n            <input type=\"submit\" value=\"");
  responsebody += THttpUtility::htmlEscape(H::tr("Upload picture"));
  responsebody += tr("\">\n        </div>\n\n</form>\n\n");
  responsebody += QVariant(linkTo(H::tr("Back"), H::createUrl("attachments", 1))).toString();
  responsebody += tr("\n\n\n\n\n");

  return responsebody;
}

Q_DECLARE_METATYPE(attachments_editView)
T_REGISTER_VIEW(attachments_editView)

#include "attachments_editView.moc"
