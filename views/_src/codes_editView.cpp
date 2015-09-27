#include <QtCore>
#include <TreeFrogView>
#include "codes.h" 
#include "attachments.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT codes_editView : public TActionView
{
  Q_OBJECT
public:
  codes_editView() : TActionView() { }
  codes_editView(const codes_editView &) : TActionView() { }
  QString toString();
};

QString codes_editView::toString()
{
  responsebody.reserve(6682);
      responsebody += tr("\n");
  tfetch(QVariantMap, codes);
  responsebody += tr("\n");
  tfetch(Users, user);
  responsebody += tr("\n        <h3>");
  responsebody += THttpUtility::htmlEscape(H::tr("Edit"));
  responsebody += tr(" ");
  responsebody += THttpUtility::htmlEscape(codes["title"].toString().isEmpty() ? QString(H::tr("Code") + " #%1").arg(codes["id"].toString()) : codes["title"]);
  responsebody += tr("</h3>\n\n");
  responsebody += QVariant(formTag(H::createUrl({"codes", "save", codes["id"].toString()}, httpRequest().queryItemValue("page", "1")), Tf::Post, true)).toString();
  responsebody += tr("\n<input type=\"hidden\" name=\"codes[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(codes["id"]);
  responsebody += tr("\" readonly=\"readonly\" />\n\n        <div class=\"field\">\n        <label>");
  responsebody += THttpUtility::htmlEscape(H::tr("Title"));
  responsebody += tr("</label>\n        <input type=\"text\" name=\"codes[title]\" value=\"");
  responsebody += THttpUtility::htmlEscape(codes["title"]);
  responsebody += tr("\" style=\"width: 400px\" class=\"form-input\" />\n        </div>\n        <div class=\"bbcodes\">\n            <div class=\"bold\">\n                ");
  responsebody += QVariant(linkTo("B", QUrl("#"), Tf::Get, "", a("class", "bbcode html") | a("data-editor", "b"))).toString();
  responsebody += tr("\n                ");
  responsebody += QVariant(linkTo("I", QUrl("#"), Tf::Get, "", a("class", "bbcode cursive") | a("data-editor", "i"))).toString();
  responsebody += tr("\n                ");
  responsebody += QVariant(linkTo("U", QUrl("#"), Tf::Get, "", a("class", "bbcode underline") | a("data-editor", "u"))).toString();
  responsebody += tr("\n                ");
  responsebody += QVariant(linkTo("S", QUrl("#"), Tf::Get, "", a("class", "bbcode del") | a("data-editor", "s"))).toString();
  responsebody += tr("\n                ");
  responsebody += QVariant(linkTo("IMG", QUrl("#"), Tf::Get, "", a("class", "bbcode html") | a("data-editor", "img"))).toString();
  responsebody += tr("\n                ");
  responsebody += QVariant(linkTo("URL", QUrl("#"), Tf::Get, "", a("class", "bbcode html") | a("data-editor", "url"))).toString();
  responsebody += tr("\n            </div>\n            ");
  for(const auto& tag: H::codesTitles().toStdMap()) {;
  responsebody += tr("                ");
  responsebody += QVariant(linkTo(tag.first, QUrl("#"), Tf::Get, a("class", "bbcode") | a("data-editor", tag.second))).toString();
  responsebody += tr("\n            ");
  };
  responsebody += tr("        </div>\n        <br>\n        <div class=\"field\" style=\"\">\n        ");
  QString dataEditor = H::parseCode(codes["code"].toString(), true);
            if(dataEditor.isEmpty())
                dataEditor = "javascript";
  responsebody += tr("            <textarea rows=\"15\" style=\"width:700px\" data-editor='");
  responsebody += THttpUtility::htmlEscape(dataEditor.toLower());
  responsebody += tr("' class=\"form-input\" required>\n");
  responsebody += THttpUtility::htmlEscape(codes["code"]);
  responsebody += tr("\n        </textarea>\n        </div>\n<input type=\"hidden\" id=\"code\" name=\"codes[code]\" value='");
  responsebody += THttpUtility::htmlEscape(codes["code"]);
  responsebody += tr("'>\n<br>\n<small><i>");
  responsebody += THttpUtility::htmlEscape(H::tr("Note: If picture less than 150x150, it will be resized to it"));
  responsebody += tr("</i></small><br>\n<input type=\"file\" name=\"attachments[]\" multiple>\n\n");
  const auto& attachments = Attachments::getAll(codes["id"].toInt());

    if(attachments.count()) {;
  responsebody += tr("    <br>\n        <fieldset>\n            <legend> ");
  responsebody += THttpUtility::htmlEscape(H::tr("Attachments"));
  responsebody += tr(" </legend>\n            ");
  for(const auto& attach: attachments) {;
  responsebody += tr("                <div class=\"attach_item\">\n                   <a href=\"/images/uploads/");
  responsebody += THttpUtility::htmlEscape(attach.image());
  responsebody += tr("\" rel=\"prettyPhoto[gallery]\">\n                       ");
  responsebody += QVariant(imageTag("/images/uploads/" + attach.image(), a("class", "attach"))).toString();
  responsebody += tr("\n                   </a>\n                   <a href=\"");
  responsebody += THttpUtility::htmlEscape(H::createUrl({"attachments", QString::number(attach.id()), "remove"}));
  responsebody += tr("\" class=\"remove link\">");
  responsebody += THttpUtility::htmlEscape(H::tr("Destroy"));
  responsebody += tr("</a>\n                </div>\n            ");
  };
  responsebody += tr("        </fieldset>\n");
  };
  responsebody += tr("\n");
  if(controller()->isUserLoggedIn()) {;
  responsebody += tr("        <div class=\"field\">\n            <label>");
  responsebody += THttpUtility::htmlEscape(H::tr("Status"));
  responsebody += tr("</label>\n            <input type=\"text\" name=\"codes[status]\" value=\"");
  responsebody += THttpUtility::htmlEscape(codes["status"]);
  responsebody += tr("\">\n        </div>\n        <div class=\"field\">\n            <label>");
  responsebody += THttpUtility::htmlEscape(H::tr("Editable"));
  responsebody += tr("</label>\n            <input type=\"text\" name=\"codes[editable]\" value='");
  responsebody += THttpUtility::htmlEscape(codes["editable"]);
  responsebody += tr("'>\n        </div>\n        <div class=\"field\">\n            <label>");
  responsebody += THttpUtility::htmlEscape(H::tr("Show from"));
  responsebody += tr("</label>\n            <input type=\"text\" name=\"codes[showFrom]\" value='");
  responsebody += THttpUtility::htmlEscape(codes["showFrom"]);
  responsebody += tr("'>\n        </div>\n");
  };
  responsebody += tr("         <div class=\"actions\" style=\"margin-top: 20px;\">\n            <input type=\"submit\" id=\"save_code\" value=\"");
  responsebody += THttpUtility::htmlEscape(H::tr("Save"));
  responsebody += tr("\" />\n        </div>\n        </form>\n\n");
  responsebody += QVariant(linkTo(H::tr("Show"), H::createUrl({"codes", codes["id"].toString()}))).toString();
  responsebody += tr("\n\n<script type=\"text/javascript\">\n        $(function() {\n              $('a.remove').click(function() {\n                  var parent = $(this).parent()\n                  if(!confirm(\"");
  responsebody += THttpUtility::htmlEscape(H::tr("Are you sure?"));
  responsebody += tr("\"))\n                    return false;\n                  $.post($(this).attr('href'), function() {\n                      parent.remove()\n                  })\n                  return false;\n              })\n          })\n</script>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(codes_editView)
T_REGISTER_VIEW(codes_editView)

#include "codes_editView.moc"
