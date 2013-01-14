#ifndef DLGLISTSELECTOR_H
#define DLGLISTSELECTOR_H

#include <QDialog>

namespace Ui {
class dlgListSelector;
}

class dlgListSelector : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgListSelector(QWidget *parent = 0);
    ~dlgListSelector();
    void addElements(QStringList elements);
    QString selectedElement();
private:
    Ui::dlgListSelector *ui;
};

#endif // DLGLISTSELECTOR_H
