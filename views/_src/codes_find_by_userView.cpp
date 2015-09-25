#include <QtCore>
#include <TreeFrogView>
#include "codes.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT codes_find_by_userView : public TActionView
{
  Q_OBJECT
public:
  codes_find_by_userView() : TActionView() { }
  codes_find_by_userView(const codes_find_by_userView &) : TActionView() { }
  QString toString();
};

QString codes_find_by_userView::toString()
{
  responsebody.reserve(850);
    responsebody += tr("\n");
  tfetch(QString, error);
  if(error.isEmpty()) {;
  tfetch(QList<Codes>, codes);
  tfetch(Users, user);
  responsebody += THttpUtility::htmlEscape(H::tr("Found"));
  responsebody += tr(" ");
  responsebody += THttpUtility::htmlEscape(codes.count());
  responsebody += tr(" ");
  responsebody += THttpUtility::htmlEscape(H::tr("message(s) by"));
  responsebody += tr(" <b>");
  responsebody += THttpUtility::htmlEscape(user.username());
  responsebody += tr("</b>:<br><br>\n    ");
  for(const auto& code: codes) {;
  responsebody += tr("\n");
  responsebody += QVariant(linkTo(code.title(), H::createUrl({"codes", QString::number(code.id())}))).toString();
  responsebody += tr("<br>\n    ");
  };
  } else {;
  responsebody += tr("    ");
  responsebody += QVariant(error).toString();
  responsebody += tr("\n");
  };

  return responsebody;
}

Q_DECLARE_METATYPE(codes_find_by_userView)
T_REGISTER_VIEW(codes_find_by_userView)

#include "codes_find_by_userView.moc"
