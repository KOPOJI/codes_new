#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT account_formView : public TActionView
{
  Q_OBJECT
public:
  account_formView() : TActionView() { }
  account_formView(const account_formView &) : TActionView() { }
  QString toString();
};

QString account_formView::toString()
{
  responsebody.reserve(1138);
  responsebody += QVariant(renderPartial("_form_header")).toString();
  responsebody += tr("\n\n<h2>");
  responsebody += THttpUtility::htmlEscape(H::tr("Sign in"));
  responsebody += tr("</h2>\n\n");
  responsebody += QVariant(formTag(H::createUrl({"user", "login"}))).toString();
  responsebody += tr("\n    <div>\n      E-mail\n      <input type=\"email\" name=\"username\" value=\"\" class=\"form-input\" autofocus=\"true\" required>\n    </div>\n<br>\n    <div>\n    ");
  responsebody += THttpUtility::htmlEscape(H::tr("Password"));
  responsebody += tr("\n    <input type=\"password\" name=\"password\" class=\"form-input\" required>\n    </div>\n    <br>\n    <div>\n        <input type=\"checkbox\" name=\"remember\">\n        ");
  responsebody += THttpUtility::htmlEscape(H::tr("Remember me"));
  responsebody += tr("\n    </div>\n\n          <br>\n    <div>\n    <input type=\"submit\" value=\"");
  responsebody += THttpUtility::htmlEscape(H::tr("Sign"));
  responsebody += tr("\" class=\"button\">\n    </div>\n</form>\n\n");
  responsebody += QVariant(renderPartial("_form_footer")).toString();
  responsebody += tr("\n");

  return responsebody;
}

Q_DECLARE_METATYPE(account_formView)
T_REGISTER_VIEW(account_formView)

#include "account_formView.moc"
