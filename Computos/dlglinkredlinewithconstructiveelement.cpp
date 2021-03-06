#include "dlglinkredlinewithconstructiveelement.h"
#include "ui_dlglinkredlinewithconstructiveelement.h"
#include <QColorDialog>
#include "datastore.h"

dlgLinkRedlineWithConstructiveElement::dlgLinkRedlineWithConstructiveElement(QString projectName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgLinkRedlineWithConstructiveElement)
{
    ui->setupUi(this);
    LoadElements(projectName);
    project = projectName;
}

dlgLinkRedlineWithConstructiveElement::~dlgLinkRedlineWithConstructiveElement()
{
    delete ui;
}

void dlgLinkRedlineWithConstructiveElement::setImage(QImage image)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    QPixmap pixmap = QPixmap::fromImage(image);
    scene->addPixmap(pixmap);
    ui->snapshot->setScene(scene);
}

QString dlgLinkRedlineWithConstructiveElement::Author()
{
    return ui->lblAuthor->text();
}

QColor dlgLinkRedlineWithConstructiveElement::Color()
{
    QPalette palette = ui->color->palette();
    return palette.color(ui->color->backgroundRole());
}

QString dlgLinkRedlineWithConstructiveElement::Annotation()
{
    return ui->txtAnnotation->text();
}

QString dlgLinkRedlineWithConstructiveElement::Element()
{
    return ui->cboMaterial->currentText();
}

void dlgLinkRedlineWithConstructiveElement::on_btnNewMaterial_pressed()
{
    emit createNewElement();
    LoadElements(project);
}

void dlgLinkRedlineWithConstructiveElement::on_btnPickColor_pressed()
{
    QColorDialog dlg(this);
    dlg.exec();
    if (dlg.result() == dlg.Accepted)
    {
        QPalette palette = ui->color->palette();
        palette.setColor(ui->color->backgroundRole(), dlg.currentColor());
        ui->color->setPalette(palette);
    }
}

void dlgLinkRedlineWithConstructiveElement::LoadElements(QString projectName)
{
    ui->cboMaterial->clear();
    boost::shared_ptr<QStringList> projects = DataStore::getInstance()->getProject(projectName)->getAllElementoConstructivoNames();
    ui->cboMaterial->addItems(*projects);
}
