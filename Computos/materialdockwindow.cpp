#include "materialdockwindow.h"
#include "ui_materialdockwindow.h"
#include <boost/shared_ptr.hpp>
#include "datastore.h"

MaterialDockWindow::MaterialDockWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MaterialDockWindow)
{
    ui->setupUi(this);
    QString all = "";
    LoadMateriales(all);
    connect(DataStore::getInstance()->getMaterialLibrary(), SIGNAL(saved()), this, SLOT(LibrarySaved()));
}

MaterialDockWindow::~MaterialDockWindow()
{
    delete ui;
}


void MaterialDockWindow::LoadMateriales(QString &filter)
{
    ui->treeMateriales->clear();
    // Aca tengo que pedir la lista de materiales e ir cargandola
    boost::shared_ptr<QStringList> materiales = DataStore::getInstance()->getMaterialLibrary()->getAllNames(filter, true);

    foreach(QString material, *materiales)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText(0, material);
        materialLibrary::Elemento *elemento = DataStore::getInstance()->getMaterialLibrary()->getElemento(material);
        if (elemento->getMeasureUnit() != NULL)
            item->setText(1, elemento->getMeasureUnit()->getDisplayName());
        else
            item->setText(1, "");
        item->setText(2, elemento->getTagsString());
        ui->treeMateriales->insertTopLevelItem(0, item);

        QString tooltip = "<p><b>%1</b></p>"
                "<p>(%2)</p>"
                "<p>%3</p>";
        tooltip = tooltip.arg(material).arg(elemento->getTagsString()).arg(elemento->getDescription());
/*                "<ul>"
                  "<li>You can <i>format</i> text.</li>"
                  "<li><b>Bold</b> is possible too.</li>"
                  "<li>And the <font color='#22aaff'>color</font> and "
                    "<font size='+2'>size</font>.</li>"
                "</ul>"
                "<p>You can do ordered lists as well.</p>"
                "<ol>"
                  "<li>First.</li>"
                  "<li>Second.</li>"
                  "<li>Third.</li>"
                "</ol>";*/
        item->setToolTip(0, tooltip);

    }
}

void MaterialDockWindow::on_btnBorrarBusqueda_pressed()
{
    ui->txtKeys->clear();
    on_btnBuscar_pressed();
}

void MaterialDockWindow::on_btnBuscar_pressed()
{
    QString filtro = ui->txtKeys->text().simplified();
    LoadMateriales(filtro);
}

void MaterialDockWindow::LibrarySaved()
{
    QString filtro = ui->txtKeys->text();
    LoadMateriales(filtro);
}
