#include "dlgsuperficiepoligonal.h"
#include "ui_dlgsuperficiepoligonal.h"
#include <QMenu>

dlgSuperficiePoligonal::dlgSuperficiePoligonal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgSuperficiePoligonal)
{
    ui->setupUi(this);
    ui->tblPoints->setColumnCount(2);
    QStringList headers;
    headers /*<< "#" */ << tr("x") << tr("y");
    ui->tblPoints->setHorizontalHeaderLabels(headers);
}

dlgSuperficiePoligonal::~dlgSuperficiePoligonal()
{
    delete ui;
}

void dlgSuperficiePoligonal::on_buttonBox_accepted()
{
    coordinates.clear();
    for (int i = 0; i < ui->tblPoints->rowCount(); i++)
    {
        cantidades::POINT_2D pt;
        pt.x = ui->tblPoints->item(i, 0)->text().toDouble();
        pt.y = ui->tblPoints->item(i, 1)->text().toDouble();
        coordinates.push_back(pt);
    }
}

void dlgSuperficiePoligonal::on_buttonBox_rejected()
{
}


void dlgSuperficiePoligonal::addCoordinate()
{
    int row = ui->tblPoints->rowCount();
    ui->tblPoints->insertRow(row);
}

void dlgSuperficiePoligonal::addCoordinate(cantidades::POINT_2D pt)
{
    addCoordinate();
    int row = ui->tblPoints->rowCount() - 1;
    QTableWidgetItem *item = new QTableWidgetItem(QString::number(pt.x));
    ui->tblPoints->setItem(row, 0, item);
    item = new QTableWidgetItem(QString::number(pt.y));
    ui->tblPoints->setItem(row, 1, item);
}

void dlgSuperficiePoligonal::setCoordinates(QVector<cantidades::POINT_2D> &newCoordinates)
{
    coordinates = newCoordinates;
    ui->tblPoints->clear();
    foreach(cantidades::POINT_2D pt, coordinates)
    {
        addCoordinate(pt);
    }
}

QVector<cantidades::POINT_2D> dlgSuperficiePoligonal::Coordinates()
{
    return coordinates;
}

void dlgSuperficiePoligonal::setFormula(QString formula)
{
    ui->lblFormula->setText(formula);
}

void dlgSuperficiePoligonal::on_tblPoints_customContextMenuRequested(const QPoint &pos)
{
    QMenu *menu = new QMenu(this);

    menu->addAction(ui->actionAddPoint);
    menu->addAction(ui->actionDelete_Coordinate);
    menu->addSeparator();
    menu->addAction(ui->actionMove_Up);
    menu->addAction(ui->actionMove_Down);

    menu->exec(ui->tblPoints->mapToGlobal(pos));
}

void dlgSuperficiePoligonal::on_actionAddPoint_triggered()
{
    addCoordinate();
}

void dlgSuperficiePoligonal::on_actionDelete_Coordinate_triggered()
{
    ui->tblPoints->removeRow(ui->tblPoints->currentRow());
}

void dlgSuperficiePoligonal::swapCell(int row0, int col0, int row1, int col1)
{
/*    QTableWidgetItem *item = ui->tblPoints->item(row1, col1);
    ui->tblPoints->setItem(row1, col1, ui->tblPoints->item(row0, col0));
    ui->tblPoints->setItem(row0, col0, item);
    */
    QString aux = ui->tblPoints->item(row1, col1)->text();
    ui->tblPoints->item(row1, col1)->setText(ui->tblPoints->item(row0, col0)->text());
    ui->tblPoints->item(row0, col0)->setText(aux);
}

void dlgSuperficiePoligonal::moveRow(int row, int direction)
{
    if ((row > 1) && (direction == -1))
        return;

    if ((row == ui->tblPoints->rowCount() -1) && (direction == 1))
        return;

    int newPos = row + direction;

    swapCell(row, 0, newPos, 0);
    swapCell(row, 1, newPos, 1);
}

void dlgSuperficiePoligonal::on_actionMove_Up_triggered()
{
    moveRow(ui->tblPoints->currentRow(), -1);
}

void dlgSuperficiePoligonal::on_actionMove_Down_triggered()
{
    moveRow(ui->tblPoints->currentRow(), 1);
}
