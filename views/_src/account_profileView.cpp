#include <QtCore>
#include <TreeFrogView>
#include "users.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT account_profileView : public TActionView
{
  Q_OBJECT
public:
  account_profileView() : TActionView() { }
  account_profileView(const account_profileView &) : TActionView() { }
  QString toString();
};

QString account_profileView::toString()
{
  responsebody.reserve(7262);
    responsebody += tr("\n");
  tfetch(Users, user);
  tfetch(Profiles, profile);
  tfetch(bool, canBeEdited);
  responsebody += tr("\n\n<div id=\"info\"></div>\n<h3>");
  responsebody += THttpUtility::htmlEscape(user.username());
  responsebody += tr(" ");
  responsebody += QVariant(H::userStatusImage(user.isOnline())).toString();
  responsebody += tr("</h3>\n\n<div id=\"profilePage\">\n    <div id=\"leftCol\">\n        <div id=\"photo\">\n            ");
  const bool& avatarExists = !profile.avatar().isEmpty() && H::imageExists("avatars/" + profile.avatar());
            if(avatarExists) {;
  responsebody += tr("                ");
  responsebody += QVariant(imageTag("/images/avatars/" + profile.avatar())).toString();
  responsebody += tr("\n                <br>\n                <br>\n            ");
  };
  responsebody += tr("\n            ");
  if(canBeEdited) {;
  responsebody += tr("                ");
  responsebody += QVariant(formTag(H::createUrl({"user", QString::number(user.id()), "profile_avatar"}), Tf::Post, true)).toString();
  responsebody += tr("\n\n");
  responsebody += QVariant(inputFileTag("avatar", profile.avatar())).toString();
  responsebody += tr("<br>\n");
  responsebody += QVariant(inputHiddenTag("old_avatar", profile.avatar())).toString();
  responsebody += tr("<br>\n\n                    ");
  if(avatarExists) {;
  responsebody += tr("                        ");
  responsebody += THttpUtility::htmlEscape(H::tr("Delete avatar"));
  responsebody += tr(" ");
  responsebody += QVariant(checkBoxTag("delete_avatar", "0", false)).toString();
  responsebody += tr("<br>\n                    ");
  };
  responsebody += tr("\n                    ");
  responsebody += QVariant(submitTag(H::tr("Save"), a("class", "button"))).toString();
  responsebody += tr("\n\n                </form>\n            ");
  };
  responsebody += tr("\n        </div>\n        <div id=\"profileOptions\"></div>\n    </div>\n    <div id=\"info\">\n\n        ");
  const QString& editLink = linkTo(imageTag(imagePath("userfield_edit.gif")), QUrl("#"), Tf::Get, a("class", "edit_info"));
  responsebody += tr("\n        <p>\n            <strong>");
  responsebody += THttpUtility::htmlEscape(H::tr("Name"));
  responsebody += tr(":</strong>\n            <span");
  responsebody += THttpUtility::htmlEscape(H::specifiedClass(profile.name()));
  responsebody += tr(">");
  responsebody += THttpUtility::htmlEscape(H::specifiedText(profile.name()));
  responsebody += tr("</span>\n            ");
  if(canBeEdited) {;
  responsebody += tr("                ");
  responsebody += QVariant(editLink).toString();
  responsebody += tr("\n                ");
  responsebody += QVariant(inputTextTag("name", profile.name(), a("class", "hidden"))).toString();
  responsebody += tr("\n            ");
  };
  responsebody += tr("        </p>\n\n        <p>\n            <strong>");
  responsebody += THttpUtility::htmlEscape(H::tr("Interests"));
  responsebody += tr(":</strong>\n            <span");
  responsebody += THttpUtility::htmlEscape(H::specifiedClass(profile.interests()));
  responsebody += tr(">");
  responsebody += THttpUtility::htmlEscape(H::specifiedText(profile.interests()));
  responsebody += tr("</span>\n            ");
  if(canBeEdited) {;
  responsebody += tr("                ");
  responsebody += QVariant(editLink).toString();
  responsebody += tr("\n                ");
  responsebody += QVariant(inputTextTag("interests", profile.interests(), a("class", "hidden"))).toString();
  responsebody += tr("\n            ");
  };
  responsebody += tr("        </p>\n\n        <p>\n            <strong>");
  responsebody += THttpUtility::htmlEscape(H::tr("Experience"));
  responsebody += tr(":</strong>\n            <span");
  responsebody += THttpUtility::htmlEscape(H::specifiedClass(profile.exp()));
  responsebody += tr(">");
  responsebody += THttpUtility::htmlEscape(H::specifiedText(profile.exp()));
  responsebody += tr("</span>\n            ");
  if(canBeEdited) {;
  responsebody += tr("                ");
  responsebody += QVariant(editLink).toString();
  responsebody += tr("\n                ");
  responsebody += QVariant(inputTextTag("exp", profile.exp(), a("class", "hidden"))).toString();
  responsebody += tr("\n            ");
  };
  responsebody += tr("        </p>\n\n        <p>\n            <strong>");
  responsebody += THttpUtility::htmlEscape(H::tr("About me"));
  responsebody += tr(":</strong>\n            <span");
  responsebody += THttpUtility::htmlEscape(H::specifiedClass(profile.aboutMe()));
  responsebody += tr(">");
  responsebody += THttpUtility::htmlEscape(H::specifiedText(profile.aboutMe()));
  responsebody += tr("</span>\n            ");
  if(canBeEdited) {;
  responsebody += tr("                ");
  responsebody += QVariant(editLink).toString();
  responsebody += tr("\n                ");
  responsebody += QVariant(inputTextTag("about_me", profile.aboutMe(), a("class", "hidden"))).toString();
  responsebody += tr("\n            ");
  };
  responsebody += tr("        </p>\n\n        <p>\n            <strong>");
  responsebody += THttpUtility::htmlEscape(H::tr("Signature"));
  responsebody += tr(":</strong>\n            <span");
  responsebody += THttpUtility::htmlEscape(H::specifiedClass(profile.signature()));
  responsebody += tr(">");
  responsebody += THttpUtility::htmlEscape(H::specifiedText(profile.signature()));
  responsebody += tr("</span>\n            ");
  if(canBeEdited) {;
  responsebody += tr("                ");
  responsebody += QVariant(editLink).toString();
  responsebody += tr("\n                ");
  responsebody += QVariant(inputTextTag("signature", profile.signature(), a("class", "hidden"))).toString();
  responsebody += tr("\n            ");
  };
  responsebody += tr("        </p>\n    </div>\n    <div class=\"clear\"></div>\n</div>\n\n<script>\n$(function() {\n    $('#profilePage a.edit_info').click(function() {\n        $(this).parent().children('input').removeClass('hidden')\n        $(this).parent().children('input').focus()\n        return false\n    })\n\n    $('#profilePage input').blur(function() {\n\n        if($(this).attr('type') != 'text')\n            return\n        if(this.value != $(this).parent().children('span').html())\n        {\n            var params = {id: ");
  responsebody += THttpUtility::htmlEscape(user.id());
  responsebody += tr("}\n            params[this.name] = this.value\n            $.post('/user/profile.html', params, function(ans) {\n                var info = $('#info')\n                info.removeClass()\n                if(ans)\n                {\n                    info.text('");
  responsebody += THttpUtility::htmlEscape(H::tr("Profile was successfully updated"));
  responsebody += tr("')\n                    info.addClass(\"alert alert-success\")\n                }\n                else\n                {\n                    info.text('");
  responsebody += THttpUtility::htmlEscape(H::tr("Updating profile failed, sorry"));
  responsebody += tr("')\n                    info.addClass(\"alert alert-warning\")\n                }\n            })\n        }\n        $(this).addClass('hidden')\n        $(this).parent().children('span').html(this.value)\n    })\n})\n</script>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(account_profileView)
T_REGISTER_VIEW(account_profileView)

#include "account_profileView.moc"
