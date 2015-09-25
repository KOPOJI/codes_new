#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_errorView : public TActionView
{
  Q_OBJECT
public:
  partial_errorView() : TActionView() { }
  partial_errorView(const partial_errorView &) : TActionView() { }
  QString toString();
};

QString partial_errorView::toString()
{
  responsebody.reserve(1593);
  responsebody += tr("<style>\n  body {\n    background-color: #EFEFEF;\n    color: #2E2F30;\n    text-align: center;\n    font-family: arial, sans-serif;\n  }\n  div.dialog {\n    width: 25em;\n    margin: 4em auto 0 auto;\n    border: 1px solid #CCC;\n    border-right-color: #999;\n    border-left-color: #999;\n    border-bottom-color: #BBB;\n    border-top: #B00100 solid 4px;\n    border-top-left-radius: 9px;\n    border-top-right-radius: 9px;\n    background-color: white;\n    padding: 7px 4em 0 4em;\n  }\n  h1 {\n    font-size: 100%;\n    color: #730E15;\n    line-height: 1.5em;\n  }\n  body > p {\n    width: 33em;\n    margin: 0 auto 1em;\n    padding: 1em 0;\n    background-color: #F7F7F7;\n    border: 1px solid #CCC;\n    border-right-color: #999;\n    border-bottom-color: #999;\n    border-bottom-left-radius: 4px;\n    border-bottom-right-radius: 4px;\n    border-top-color: #DADADA;\n    color: #666;\n    box-shadow: 0 3px 8px rgba(50, 50, 50, 0.17);\n  }\n</style>\n");
  tfetch(QString, message);
  responsebody += tr("<div class=\"dialog\">\n  ");
  if(message.isEmpty()) {;
  responsebody += tr("  <h1>");
  responsebody += THttpUtility::htmlEscape(H::tr("The page you were looking for doesn't exist."));
  responsebody += tr("</h1>\n  ");
  } else {;
  responsebody += tr("    <h1>");
  responsebody += THttpUtility::htmlEscape(message);
  responsebody += tr("</h1>\n  ");
  };
  responsebody += tr("  <p>");
  responsebody += THttpUtility::htmlEscape(H::tr("You may have mistyped the address or the page may have moved."));
  responsebody += tr("</p>\n</div>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(partial_errorView)
T_REGISTER_VIEW(partial_errorView)

#include "partial_errorView.moc"
