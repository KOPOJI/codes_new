#include <QtCore>
#include <TreeFrogView>
#include "codes.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT account_usersView : public TActionView
{
  Q_OBJECT
public:
  account_usersView() : TActionView() { }
  account_usersView(const account_usersView &) : TActionView() { }
  QString toString();
};

QString account_usersView::toString()
{
  responsebody.reserve(2921);
    responsebody += tr("<div class=\"post\">\n        <h2>");
  responsebody += THttpUtility::htmlEscape(H::tr("Users list"));
  responsebody += tr(" (");
  responsebody += THttpUtility::htmlEscape(Users::count());
  responsebody += tr(")</h2>\n\n        ");
  if(!Users::count()) {;
  responsebody += tr("                ");
  responsebody += THttpUtility::htmlEscape(H::tr("Users not found"));
  responsebody += tr("\n        ");
  } else {;
  responsebody += tr("                <table class=\"table table-hover\">\n                        <thead>\n                                <tr>\n                                        <th>");
  responsebody += THttpUtility::htmlEscape(H::tr("Username"));
  responsebody += tr("</th>\n                                        <th>");
  responsebody += THttpUtility::htmlEscape(H::tr("Registration date"));
  responsebody += tr("</th>\n                                        <th>");
  responsebody += THttpUtility::htmlEscape(H::tr("Messages count"));
  responsebody += tr("</th>\n                                        <th>");
  responsebody += THttpUtility::htmlEscape(H::tr("Last visit"));
  responsebody += tr("</th>\n                                        <th>");
  responsebody += THttpUtility::htmlEscape(H::tr("Avatar"));
  responsebody += tr("</th>\n                                </tr>\n                        </thead>\n                        <tbody>\n                        ");
  for(const auto& user: Users::getAll()) {;
  responsebody += tr("                                        <tr>\n                                                <td>");
  responsebody += QVariant(H::userStatusImage(user.isOnline())).toString();
  responsebody += tr(" <b>");
  responsebody += QVariant(linkTo(user.username(), H::createUrl({"user", QString::number(user.id())}))).toString();
  responsebody += tr("</b></td>\n                                                <td>");
  responsebody += THttpUtility::htmlEscape(user.createdAt().toString("dd.MM.yyyy в hh:mm:ss"));
  responsebody += tr("</td>\n                           <td>");
  responsebody += QVariant(linkTo(QString::number(Codes::userCodesCount(user.id())), H::createUrl({"codes", "find_by_user", QString::number(user.id())}), Tf::Get, "", a("class", "link"))).toString();
  responsebody += tr("</td>\n                                                <td>");
  responsebody += THttpUtility::htmlEscape(user.lastSignInAt().toString("dd.MM.yyyy в hh:mm:ss"));
  responsebody += tr("</td>\n                                                <td style=\"text-align:center\">");
  /*= user.profile.avatar? ? image_tag(user.profile.avatar_url, class: 'photo-icon') : ' - ' */
  responsebody += tr("</td>\n                                        </tr>\n                                ");
  };
  responsebody += tr("                        </tbody>\n                </table>\n        ");
  };
  responsebody += tr("</div>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(account_usersView)
T_REGISTER_VIEW(account_usersView)

#include "account_usersView.moc"
