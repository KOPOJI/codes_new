#include <QtCore>
#include <TreeFrogView>
#include "codes.h" 
#include "attachments.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT codes_showView : public TActionView
{
  Q_OBJECT
public:
  codes_showView() : TActionView() { }
  codes_showView(const codes_showView &) : TActionView() { }
  QString toString();
};

QString codes_showView::toString()
{
  responsebody.reserve(2492);
      tfetch(Codes, code);
  responsebody += tr("\n<div class=\"post\">\n        <h3>");
  responsebody += THttpUtility::htmlEscape(code.title());
  responsebody += tr("</h3>\n<div style=\"font-size:10px;font-style:italic;border-bottom: 1px solid #CCC;padding:3px;margin:3px;padding-left:15px\">\n        ");
  responsebody += THttpUtility::htmlEscape(H::tr("Added by"));
  responsebody += tr("\n            <b>");
  if(code.userId()) {;
  responsebody += THttpUtility::htmlEscape(code.author());
  } else {;
  responsebody += THttpUtility::htmlEscape(H::tr("Guest"));
  };
  responsebody += tr("</b>\n    ");
  responsebody += THttpUtility::htmlEscape(code.createdAt().toString("dd.MM.yyyy в hh:mm:ss"));
  responsebody += tr("<br>\n        ");
  responsebody += THttpUtility::htmlEscape(H::tr("Last edited"));
  responsebody += tr(": ");
  responsebody += THttpUtility::htmlEscape(code.updatedAt().toString("dd.MM.yyyy " + H::tr("at") + " hh:mm:ss"));
  responsebody += tr("\n      </div>\n");
  responsebody += QVariant(H::parseCode(code.code())).toString();
  responsebody += tr("\n        <input type=\"hidden\" name=\"code\" id=\"code\">\n    </div>\n\n");
  const auto& attachments = Attachments::getAll(code.id());

    if(attachments.count()) {;
  responsebody += tr("    <br>\n        <fieldset>\n            <legend> ");
  responsebody += THttpUtility::htmlEscape(H::tr("Attachments"));
  responsebody += tr(" </legend>\n            ");
  for(const auto& attach: attachments) {;
  responsebody += tr("               <a href=\"/images/uploads/");
  responsebody += THttpUtility::htmlEscape(attach.image());
  responsebody += tr("\" rel=\"prettyPhoto[gallery]\">\n                   ");
  responsebody += QVariant(imageTag("/images/uploads/" + attach.image(), a("class", "attach"))).toString();
  responsebody += tr("\n               </a>\n            ");
  };
  responsebody += tr("        </fieldset>\n");
  };
  responsebody += tr("\n<script type=\"text/javascript\">\nvar editors = [], i = 0;\n$('.editor').each(function(key, editor) {\n    editors[i] = ace.edit(editor);\n    editors[i].setTheme(\"ace/theme/eclipse\");\n    editors[i].getSession().setMode(\"ace/mode/\" + (editor.lang ? editor.lang.toLowerCase() : 'javascript'));\n    editor.style.fontSize='16px';\n    var height = editors[i].getSession().getLength() * 18;\n    editor.style.height = (height > 500 ? 500 : (height < 150 ? 150 : height)) + 'px'\n    editors[i].setReadOnly(true)\n    ++i;\n})\n</script>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(codes_showView)
T_REGISTER_VIEW(codes_showView)

#include "codes_showView.moc"
