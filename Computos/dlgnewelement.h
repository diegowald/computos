#ifndef DLGNEWELEMENT_H
#define DLGNEWELEMENT_H

#include <QDialog>

namespace Ui {
class dlgNewElement;
}

class dlgNewElement : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgNewElement(QWidget *parent = 0);
    ~dlgNewElement();
    
    void setPosibleNombreElemento(QString nombre);
    QString NombreElemento();

    void setTags(QString tags);
    QString Tags();

    void setDescripcion(QString descripcion);
    QString Descripcion();
private slots:
    void on_buttonBox_accepted();

private:
    Ui::dlgNewElement *ui;

    void LoadComboMeasureUnits();
};

#endif // DLGNEWELEMENT_H
