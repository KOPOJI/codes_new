#include "attachmentscontroller.h"
#include "attachments.h"


AttachmentsController::AttachmentsController(const AttachmentsController &)
    : ApplicationController()
{ }


void AttachmentsController::index()
{
    QList<Attachments> attachmentsList = Attachments::getAll();
    texport(attachmentsList);

    auto user = getUser();
    texport(user);
    render();
}

void AttachmentsController::show(const QString &pk)
{
    const int id = pk.left(pk.indexOf(QRegExp("\\.(?=html)"))).toInt();

    auto attachments = Attachments::get(id);
    texport(attachments);
    render();
}

void AttachmentsController::entry()
{
    renderEntry();
}

void AttachmentsController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    //main form
    auto form = httpRequest().formItems("attachments");

    //get choosen image
    auto &image = httpRequest().multipartFormData();

    //name of input tag
    const auto& inputName = "attachments[image]";

    //type of image
    QString imageType = image.contentType(inputName);

    imageType = imageType.mid(imageType.indexOf('/') + 1).toUpper().trimmed().replace("GIF", "PNG");

    const auto& typeRegex = QRegExp("jpe?g|png|gif", Qt::CaseInsensitive);
    const auto& nameRegex = QRegularExpression("(?<=\\.)(?:jpe?g|png|gif)$", QRegularExpression::CaseInsensitiveOption | QRegularExpression::UseUnicodePropertiesOption);

    //check image & image type
    if( image.isEmpty() || !image.size(inputName) || !imageType.contains(typeRegex) || !image.originalFileName(inputName).contains(nameRegex) )
    {
        QString error = H::tr("Wrong image format");
        tflash(error);
        redirect(H::createUrl({"attachments", "new"}));
        return ;
    }

    const QString& newImageName = H::imageResize(image.entity(inputName).uploadedFilePath(), imageType);

    if(newImageName.isEmpty())
    {
        QString error = H::tr("An error occurred while downloading picture. Please, try later");
        tflash(error);
        redirect(H::createUrl({"attachments", "new"}));
        return ;
    }

    form["image"] = newImageName;

    auto attachments = Attachments::create(form);

    if (!attachments.isNull())
    {
        QString success = H::tr("Picture was successfully uploaded");
        tflash(success);
        redirect(H::createUrl({"attachments", QString::number(attachments.id())}));
        return ;
    }

    QString error = H::tr("An error occurred while downloading picture. Please, try later");
    texport(error);
    renderEntry(form);
}

void AttachmentsController::renderEntry(const QVariantMap &attachments)
{
    texport(attachments);
    render("entry");
}

void AttachmentsController::edit(const QString &pk)
{
    if(!isUserLoggedIn())
    {
        QString error =  H::tr("Insufficient permissions to perform the operation");
        tflash(error);
        redirect(H::createUrl("attachments"));
        return ;
    }
    auto attachments = Attachments::get(pk.toInt());
    if (!attachments.isNull())
    {
        renderEdit(attachments.toVariantMap(), attachments.code());
    }
    else
    {
        redirect(H::createUrl("attachments"));
    }
}

void AttachmentsController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post || !isUserLoggedIn()) {
        return;
    }

    QString error;
    auto attachments = Attachments::get(pk.toInt());
    if (attachments.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("attachments");

    //get choosen image
    auto &image = httpRequest().multipartFormData();

    if(!image.isEmpty())
    {

        //name of input tag
        const auto& inputName = "attachments[image]";

        //type of image
        QString imageType = image.contentType(inputName);

        imageType = imageType.mid(imageType.indexOf('/') + 1).toUpper().trimmed().replace("GIF", "PNG");

        const auto& typeRegex = QRegExp("jpe?g|png|gif", Qt::CaseInsensitive);
        const auto& nameRegex = QRegularExpression("(?<=\\.)(?:jpe?g|png|gif)$", QRegularExpression::CaseInsensitiveOption | QRegularExpression::UseUnicodePropertiesOption);

        //check image & image type
        if( image.isEmpty() || !image.size(inputName) || !imageType.contains(typeRegex) || !image.originalFileName(inputName).contains(nameRegex) )
        {
            QString error = H::tr("Wrong image format");
            tflash(error);
            redirect(H::createUrl({"attachments", "new"}));
            return ;
        }

        const QString& newImageName = H::imageResize(image.entity(inputName).uploadedFilePath(), imageType);

        if(newImageName.isEmpty())
        {
            QString error = H::tr("An error occurred while downloading picture. Please, try later");
            tflash(error);
            redirect(H::createUrl({"attachments", "new"}));
            return ;
        }

        form["image"] = newImageName;

        if(!attachments.image().isEmpty())
        {
            QFile file("./public/uploads/" + attachments.image());
            if(file.exists())
                file.remove();
            file.close();
        }
    }

    attachments.setProperties(form);
    if (attachments.save()) {
        QString notice = H::tr("Picture was successfully updated");
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = H::tr("An error occurred while editing picture. Please, try later");
        texport(error);
        renderEdit(form);
    }
}

void AttachmentsController::renderEdit(const QVariantMap &attachments, const Codes& attachCode)
{
    texport(attachments);
    texport(attachCode);
    render("edit");
}

void AttachmentsController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto attachments = Attachments::get(pk.toInt());
    const auto& dir = "./public/uploads/";
    const auto& image = dir + attachments.image();
    QString notice;
    if(attachments.remove())
    {
        QFile file(image);
        if(file.exists())
            file.remove();
        file.close();
        notice = H::tr("Attachment was successfully deleted");
    }
    else
        notice = H::tr("Attachment can not be deleted, sorry");
    tflash(notice);
    redirect(H::createUrl("attachments", 1));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(attachmentscontroller)
