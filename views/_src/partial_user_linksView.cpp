#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_user_linksView : public TActionView
{
  Q_OBJECT
public:
  partial_user_linksView() : TActionView() { }
  partial_user_linksView(const partial_user_linksView &) : TActionView() { }
  QString toString();
};

QString partial_user_linksView::toString()
{
  responsebody.reserve(0);

  return responsebody;
}

Q_DECLARE_METATYPE(partial_user_linksView)
T_REGISTER_VIEW(partial_user_linksView)

#include "partial_user_linksView.moc"
