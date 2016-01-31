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
  responsebody.reserve(5749);
    responsebody += tr("\n");
  responsebody += QVariant(renderPartial("private_messages_links")).toString();
  responsebody += tr("\n<br><br>\n\n");
  tfetch(PrivateMessages, message);
  tfetch(QString, action);
  responsebody += tr("<div class=\"field\">\n<label>");
  responsebody += THttpUtility::htmlEscape(H::tr("Title"));
  responsebody += tr("</label>\n<input type=\"text\" name=\"codes[title]\" value=\"");
  responsebody += THttpUtility::htmlEscape(message.title());
  responsebody += tr("\" style=\"width: 400px\" class=\"form-input\" />\n</div>\n");
  if(action == "inbox") {;
  responsebody += tr("    <p>\n      <label>");
  responsebody += THttpUtility::htmlEscape(H::tr("From"));
  responsebody += tr(":<label>\n<strong><span");
  responsebody += THttpUtility::htmlEscape(H::specifiedClass(message.userFrom().username()));
  responsebody += tr(">\n    ");
  responsebody += QVariant(H::specifiedText(message.userFrom().username(), linkTo(message.userFrom().username(), H::createUrl({"user", QString::number(message.userFrom().id())}), Tf::Get, "", a("class", "link")))).toString();
  responsebody += tr("\n</span></strong>\n    </p>\n");
  } else {;
  responsebody += tr("    <p>\n      <label>");
  responsebody += THttpUtility::htmlEscape(H::tr("To"));
  responsebody += tr(":<label>\n<strong><span");
  responsebody += THttpUtility::htmlEscape(H::specifiedClass(message.userTo().username()));
  responsebody += tr(">\n    ");
  responsebody += QVariant(H::specifiedText(message.userTo().username(), linkTo(message.userTo().username(), H::createUrl({"user", QString::number(message.userTo().id())}), Tf::Get, "", a("class", "link")))).toString();
  responsebody += tr("\n</span></strong>\n    </p>\n");
  };
  responsebody += tr("<p>\n  Текст сообщения:\n<hr style=\"margin:3px;margin-top:-2px;\">\n<div style=\"padding:15px\">\n        ");
  responsebody += QVariant(H::parseCode(message.text())).toString();
  responsebody += tr("\n</div>\n</p>\n\n");
  if (!message.file().isEmpty() && H::fileExists(message.file())) {;
  responsebody += tr("    <p>\n      <strong>Скачать:</strong>\n");
  responsebody += QVariant(linkTo(QString("%1 (%2)").arg(H::tr("file")).arg(message.file()), QUrl("/private_messages/" + message.file()), Tf::Get, "", a("class", "link"))).toString();
  responsebody += tr("\n    </p>\n");
  };
  responsebody += tr("<hr style=\"margin:0;margin-bottom:30px\">\n\n\n        <div class=\"bbcodes\">\n            <div class=\"bold\">\n                ");
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
  responsebody += tr("        </div>\n        <br>\n        <div class=\"field\" style=\"\">\n\n            <textarea rows=\"15\" style=\"width:700px\" class=\"editor\" data-editor=\"javascript\" class=\"form-input\" required>");
  responsebody += THttpUtility::htmlEscape(message.text());
  responsebody += tr("</textarea>\n        </div>\n<input type=\"hidden\" id=\"code\" name=\"codes[code]\" value=\"");
  responsebody += THttpUtility::htmlEscape(message.text());
  responsebody += tr("\">\n\n            <div class=\"field\">\n            <small><i>");
  responsebody += THttpUtility::htmlEscape(H::tr("Note: If picture less than 150x150, it will be resized to it"));
  responsebody += tr("</i></small><br>\n            <label>");
  responsebody += THttpUtility::htmlEscape(H::tr("Image"));
  responsebody += tr("</label>\n                   <input type=\"file\" name=\"attachments[]\" multiple>\n            </div>\n\n        <script type=\"text/javascript\">\n        var editors = [], i = 0;\n        $('.editor').each(function(key, editor) {\n            editors[i] = ace.edit(editor);\n            editors[i].setTheme(\"ace/theme/eclipse\");\n            editors[i].getSession().setMode(\"ace/mode/\" + (editor.lang ? editor.lang.toLowerCase() : 'javascript'));\n            editor.style.fontSize='16px';\n            var height = editors[i].getSession().getLength() * 18;\n            editor.style.height = (height > 500 ? 500 : (height < 150 ? 150 : height)) + 'px'\n            editors[i].setReadOnly(true)\n            ++i;\n        })\n\n        var editor = document.getElementById('message')\n\n        editors[i] = ace.edit('message');\n        editors[i].setTheme(\"ace/theme/eclipse\");\n        editors[i].getSession().setMode(\"ace/mode/\" + (editor.lang ? editor.lang.toLowerCase() : 'javascript'));\n        editor.style.fontSize='16px';\n        editor.style.height = '500px'\n        </script>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(privatemessages_showView)
T_REGISTER_VIEW(privatemessages_showView)

#include "privatemessages_showView.moc"
