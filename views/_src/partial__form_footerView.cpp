#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT partial__form_footerView : public TActionView
{
  Q_OBJECT
public:
  partial__form_footerView() : TActionView() { }
  partial__form_footerView(const partial__form_footerView &) : TActionView() { }
  QString toString();
};

QString partial__form_footerView::toString()
{
  responsebody.reserve(132);
  responsebody += tr("  ");
  responsebody += QVariant(renderPartial("user_links")).toString();
  responsebody += tr("\n</div>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(partial__form_footerView)
T_REGISTER_VIEW(partial__form_footerView)

#include "partial__form_footerView.moc"
