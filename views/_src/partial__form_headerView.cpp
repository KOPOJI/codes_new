#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT partial__form_headerView : public TActionView
{
  Q_OBJECT
public:
  partial__form_headerView() : TActionView() { }
  partial__form_headerView(const partial__form_headerView &) : TActionView() { }
  QString toString();
};

QString partial__form_headerView::toString()
{
  responsebody.reserve(192);
  tfetch(QString, header);
  responsebody += tr("<div class=\"post\">\n    <h2>");
  responsebody += QVariant(H::tr(header.toStdString().c_str())).toString();
  responsebody += tr("</h2>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(partial__form_headerView)
T_REGISTER_VIEW(partial__form_headerView)

#include "partial__form_headerView.moc"
