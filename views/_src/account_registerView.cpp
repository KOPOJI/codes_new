#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT account_registerView : public TActionView
{
  Q_OBJECT
public:
  account_registerView() : TActionView() { }
  account_registerView(const account_registerView &) : TActionView() { }
  QString toString();
};

QString account_registerView::toString()
{
  responsebody.reserve(2079);
  responsebody += QVariant(renderPartial("_form_header")).toString();
  responsebody += tr("\n\n");
  tfetch(QString, login);
  tfetch(QString, email);
  tfetch(QString, pass);
  tfetch(QString, pass_confirm);
  if(httpRequest().hasForm()) {;
  techoex(message);
  responsebody += tr("</div>");
  };
  responsebody += tr("\n<h2>");
  responsebody += THttpUtility::htmlEscape(H::tr("Sign up"));
  responsebody += tr("</h2>\n\n");
  responsebody += QVariant(formTag(H::createUrl({"user", "register"}))).toString();
  responsebody += tr("\n<div>\n      <label>");
  responsebody += THttpUtility::htmlEscape(H::tr("Username"));
  responsebody += tr("</label>\n      <input type=\"text\" name=\"username\" value=\"");
  responsebody += THttpUtility::htmlEscape(login);
  responsebody += tr("\" class=\"form-input\" autofocus=\"true\" required>\n    </div>\n\n    <div>\n    <label>E-mail</label>\n    <input type=\"email\" name=\"email\" value=\"");
  responsebody += THttpUtility::htmlEscape(email);
  responsebody += tr("\" class=\"form-input\" autofocus=\"true\" required>\n    </div>\n\n    <div>\n    <label>");
  responsebody += THttpUtility::htmlEscape(H::tr("Password"));
  responsebody += tr("</label>\n    <input type=\"password\" name=\"password\" value=\"");
  responsebody += THttpUtility::htmlEscape(pass);
  responsebody += tr("\" class=\"form-input\" required>\n    </div>\n\n    <div>\n    <label>");
  responsebody += THttpUtility::htmlEscape(H::tr("Password Confirmation"));
  responsebody += tr("</label>\n    <input type=\"password\" name=\"password_confirmation\" value=\"");
  responsebody += THttpUtility::htmlEscape(pass_confirm);
  responsebody += tr("\" class=\"form-input\" required>\n    </div>\n\n    <div>\n        <input type=\"submit\" value=\"");
  responsebody += THttpUtility::htmlEscape(H::tr("Sign up"));
  responsebody += tr("\" class=\"button\">\n    </div>\n\n");
  responsebody += QVariant(endTag()).toString();
  responsebody += tr("\n\n\n");
  responsebody += QVariant(renderPartial("_form_footer")).toString();
  responsebody += tr("\n");

  return responsebody;
}

Q_DECLARE_METATYPE(account_registerView)
T_REGISTER_VIEW(account_registerView)

#include "account_registerView.moc"
