#ifndef CODESCONTROLLER_H
#define CODESCONTROLLER_H

#include "applicationcontroller.h"

#include <QImage>

class T_CONTROLLER_EXPORT CodesController : public ApplicationController
{
    Q_OBJECT
public:
    CodesController() { }
    CodesController(const CodesController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void findByUser(const QString& pk);
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &codes = QVariantMap());
    void renderEdit(const QVariantMap &codes = QVariantMap());
};

T_DECLARE_CONTROLLER(CodesController, codescontroller)

#endif // CODESCONTROLLER_H
