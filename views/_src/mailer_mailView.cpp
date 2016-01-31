#include <QtCore>
#include <TreeFrogView>
#include "users.h" 
#include "privatemessages.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT mailer_mailView : public TActionView
{
  Q_OBJECT
public:
  mailer_mailView() : TActionView() { }
  mailer_mailView(const mailer_mailView &) : TActionView() { }
  QString toString();
};

QString mailer_mailView::toString()
{
  responsebody.reserve(2035);
    responsebody += tr("\n");
    responsebody += tr("\n");
  tfetch(Users, userTo); tfetch(Users, userFrom); tfetch(PrivateMessages, message);
  responsebody += tr("\nSubject: SaveCode.RU сообщает о новом личном сообщении\nFrom: SaveCode.RU <admin@savecode.ru>\nTo: ");
  responsebody += THttpUtility::htmlEscape(userTo.username());
  responsebody += tr(" <");
  responsebody += THttpUtility::htmlEscape(userTo.email());
  responsebody += tr(">\n\nЭТО СООБЩЕНИЕ БЫЛО ОТПРАВЛЕНО АВТОМАТИЧЕСКИ, НЕ ОТВЕЧАЙТЕ НА НЕГО!\n***************************\n\nУважаемый(ая) ");
  responsebody += THttpUtility::htmlEscape(userTo.username());
  responsebody += tr(",\n\nSaveCode.RU информирует Вас, что Вы получили новое личное сообщение на SaveCode.RU от пользователя ");
  responsebody += THttpUtility::htmlEscape(userFrom.username());
  responsebody += tr(" с заголовком \"");
  responsebody += THttpUtility::htmlEscape(message.title());
  responsebody += tr("\".\n\nЧтобы прочитать сообщение в оригинале, ответить и/или удалить сообщение, Вам следует пройти по данной ссылке:\nhttp://savecode.ru/pm/inbox/");
  responsebody += THttpUtility::htmlEscape(message.id());
  responsebody += tr(".html\n\nТекст сообщения:\n***************\n");
  responsebody += THttpUtility::htmlEscape(message.text());
  responsebody += tr("\nbbcode_to_html({\n 'Quote' => [\n         /\\[quote(:.*)?=(?:&quot;|')?([-_.!? :a-zA-Z0-9А-ЯЁа-яё]*?[-_.!? :a-zA-Z0-9А-ЯЁа-яё][-_.!? :a-zA-Z0-9А-ЯЁа-яё]*?)(?:&quot;|')?\\](.*?)\\[\\/quote\\1?\\]/miu,\n         \"---Цитата (сообщение от \\\\2)---\\n\\\\3\\n---Конец цитаты---\",\n         'Quote with citation',\n         '[quote=mike]please quote me[/quote]',\n         :quote\n ],\n                                         })\n\n***************\n\nНе отвечайте на данное электронное письмо! Чтобы ответить на сообщение, Вам следует пройти по данной ссылке:\nhttp://savecode.ru/pm/inbox/");
  responsebody += THttpUtility::htmlEscape(message.id());
  responsebody += tr(".html\n\nС наилучшими пожеланиями,\nSaveCode.RU\n");

  return responsebody;
}

Q_DECLARE_METATYPE(mailer_mailView)
T_REGISTER_VIEW(mailer_mailView)

#include "mailer_mailView.moc"
