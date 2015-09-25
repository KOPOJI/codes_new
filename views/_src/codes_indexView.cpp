#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT codes_indexView : public TActionView
{
  Q_OBJECT
public:
  codes_indexView() : TActionView() { }
  codes_indexView(const codes_indexView &) : TActionView() { }
  QString toString();
};

QString codes_indexView::toString()
{
  responsebody.reserve(2471);
  responsebody += tr("<div class=\"post\">\n        <b>SaveCode.RU</b> - ");
  responsebody += THttpUtility::htmlEscape(H::tr("main_text"));
  responsebody += tr(".<br><br><br>\n        ");
  responsebody += THttpUtility::htmlEscape(H::tr("simple_save"));
  responsebody += tr(":<br><br>\n\n        <div class=\"example\">\n");
  responsebody += QVariant(linkTo(
            imageTag("insert_code/insert_code_example.png", a("class", "attach") | a("alt", "Написание кода")),
            imagePath("insert_code/insert_code_example.png"),
            Tf::Get, "", a("rel", "prettyPhoto[gallery]"))).toString();
  responsebody += tr("\n\n<b> -> </b>\n");
  responsebody += QVariant(linkTo(
            imageTag("insert_code/insert_code_example_2.png", a("class", "attach") | a("alt", "Добавление кода")),
            imagePath("insert_code/insert_code_example_2.png"),
            Tf::Get, "", a("rel", "prettyPhoto[gallery]"))).toString();
  responsebody += tr("\n\n<b> -> </b>\n");
  responsebody += QVariant(linkTo(
            imageTag("insert_code/insert_attachment_example.png", a("class", "attach") | a("alt", "Выбор кода и изображения")),
            imagePath("insert_code/insert_attachment_example.png"),
            Tf::Get, "", a("rel", "prettyPhoto[gallery]"))).toString();
  responsebody += tr("\n\n<b> -> </b>\n");
  responsebody += QVariant(linkTo(
            imageTag("insert_code/insert_attachment_example_2.png", a("class", "attach") | a("alt", "Загрузка изображения")),
            imagePath("insert_code/insert_attachment_example_2.png"),
            Tf::Get, "", a("rel", "prettyPhoto[gallery]"))).toString();
  responsebody += tr("\n\n\n<b> -> </b>\n");
  responsebody += QVariant(linkTo(
            imageTag("insert_code/result.png", a("class", "attach") | a("alt", "Результат")),
            imagePath("insert_code/result.png"),
            Tf::Get, "", a("rel", "prettyPhoto[gallery]"))).toString();
  responsebody += tr("\n</div>\n</div>\n<div>\n<br>\n");
  responsebody += THttpUtility::htmlEscape(H::tr("try"));
  responsebody += tr("\n");
  responsebody += QVariant(linkTo(H::tr("try_code"), urla("new"), Tf::Get, "", a("class", "button link"))).toString();
  responsebody += tr("\n");
  responsebody += THttpUtility::htmlEscape(H::tr("or"));
  responsebody += tr("\n");
  responsebody += QVariant(linkTo(H::tr("try_attach"), url("Attachments", "new"), Tf::Get, "", a("class", "button link"))).toString();
  responsebody += tr("\n</div>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(codes_indexView)
T_REGISTER_VIEW(codes_indexView)

#include "codes_indexView.moc"
