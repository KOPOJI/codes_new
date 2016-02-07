#ifndef ATTACHMENTSCONTROLLER_H
#define ATTACHMENTSCONTROLLER_H

#include "applicationcontroller.h"

#include "../models/codes.h"

#include <QImage>

class T_CONTROLLER_EXPORT AttachmentsController : public ApplicationController
{
    Q_OBJECT
public:
    AttachmentsController() { }
    AttachmentsController(const AttachmentsController &other);


public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &attachments = QVariantMap());
    void renderEdit(const QVariantMap &attachments = QVariantMap(), const Codes &attachCode = Codes());
};

T_DECLARE_CONTROLLER(AttachmentsController, attachmentscontroller)

#endif // ATTACHMENTSCONTROLLER_H
