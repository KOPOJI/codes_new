#include <QtCore>
#include <TreeFrogView>
#include "codes.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT codes_entryView : public TActionView
{
  Q_OBJECT
public:
  codes_entryView() : TActionView() { }
  codes_entryView(const codes_entryView &) : TActionView() { }
  QString toString();
};

QString codes_entryView::toString()
{
  responsebody.reserve(4599);
    tfetch(QVariantMap, codes);
  responsebody += tr("\n<h3>");
  responsebody += THttpUtility::htmlEscape(H::tr("Adding new code"));
  responsebody += tr("</h3>\n\n");
  responsebody += QVariant(formTag(H::createUrl({"codes", "create"}, httpRequest().queryItemValue("page", "1")), Tf::Post, true)).toString();
  responsebody += tr("\n\n\n        <div class=\"field\">\n        <label>");
  responsebody += THttpUtility::htmlEscape(H::tr("Title"));
  responsebody += tr("</label>\n        <input type=\"text\" name=\"codes[title]\" value=\"\" style=\"width: 400px\" class=\"form-input\" />\n        </div>\n        <div class=\"bbcodes\">\n            <div class=\"bold\">\n                ");
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
  responsebody += tr("        </div>\n        <br>\n        <div class=\"field\" style=\"\">\n\n            <textarea rows=\"15\" style=\"width:700px\" class=\"editor\" data-editor=\"javascript\" class=\"form-input\" required></textarea>\n        </div>\n<input type=\"hidden\" id=\"code\" name=\"codes[code]\" value=\"\">\n\n            <div class=\"field\">\n            <small><i>");
  responsebody += THttpUtility::htmlEscape(H::tr("Note: If picture less than 150x150, it will be resized to it"));
  responsebody += tr("</i></small><br>\n            <label>");
  responsebody += THttpUtility::htmlEscape(H::tr("Image"));
  responsebody += tr("</label>\n                   <input type=\"file\" name=\"attachments[]\" multiple>\n            </div>\n\n");
  if(controller()->isUserLoggedIn()) {;
  responsebody += tr("        <div class=\"field\">\n            <label>");
  responsebody += THttpUtility::htmlEscape(H::tr("Status"));
  responsebody += tr("</label>\n            <input type=\"checkbox\" name=\"codes[status]\" value=\"1\" checked>\n        </div>\n        <div class=\"field\">\n            <label>");
  responsebody += THttpUtility::htmlEscape(H::tr("Editable"));
  responsebody += tr("</label>\n            <input type=\"checkbox\" name=\"codes[editable]\" value=\"1\" checked>\n        </div>\n        <div class=\"field\">\n            <label>");
  responsebody += THttpUtility::htmlEscape(H::tr("Show from"));
  responsebody += tr("</label>\n            <input type=\"text\" name=\"codes[showFrom]\" value=\"\">\n        </div>\n");
  } else {;
  responsebody += tr("\n");
  tfetch(QString, captcha);
  responsebody += tr("\n<div class=\"field\">\n    <img id=\"captcha_code\" src=\"data:image/png;base64,");
  responsebody += THttpUtility::htmlEscape(captcha);
  responsebody += tr("\"><br>\n    <small><a href=\"#\" id=\"update_captcha\" class=\"link\">");
  responsebody += THttpUtility::htmlEscape(H::tr("Update code"));
  responsebody += tr("</a></small><br>\n    <input type=\"text\" name=\"captcha\" value=\"\">\n</div>\n<script type=\"text/javascript\">\n$(\"#update_captcha\").click(function() {\n   $.post('/captcha.html', function(data) {\n       $(\"#captcha_code\").attr(\"src\", \"data:image/png;base64,\" + data);\n   })\n   return false;\n})\n</script>\n\n");
  };
  responsebody += tr("         <div class=\"actions\" style=\"margin-top: 20px;\">\n            <input type=\"submit\" id=\"save_code\" value=\"");
  responsebody += THttpUtility::htmlEscape(H::tr("Save"));
  responsebody += tr("\" />\n        </div>\n        </form>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(codes_entryView)
T_REGISTER_VIEW(codes_entryView)

#include "codes_entryView.moc"
