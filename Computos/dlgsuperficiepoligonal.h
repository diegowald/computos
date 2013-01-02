#ifndef DLGSUPERFICIEPOLIGONAL_H
#define DLGSUPERFICIEPOLIGONAL_H

#include <QDialog>

#include "superficiepoligonal.h"

namespace Ui {
class dlgSuperficiePoligonal;
}

class dlgSuperficiePoligonal : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgSuperficiePoligonal(QWidget *parent = 0);
    ~dlgSuperficiePoligonal();
    void setCoordinates(QVector<cantidades::POINT_2D> &newCoordinates);
    void setFormula(QString formula);
    QVector<cantidades::POINT_2D> Coordinates();
    
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_tblPoints_customContextMenuRequested(const QPoint &pos);
    void on_actionAddPoint_triggered();
    void on_actionDelete_Coordinate_triggered();

    void on_actionMove_Up_triggered();

    void on_actionMove_Down_triggered();

private:

    void addCoordinate();
    void addCoordinate(cantidades::POINT_2D pt);
    void moveRow(int row, int direction);
    void swapCell(int row0, int col0, int row1, int col1);

    Ui::dlgSuperficiePoligonal *ui;

    QVector<cantidades::POINT_2D> coordinates;
};

#endif // DLGSUPERFICIEPOLIGONAL_H
