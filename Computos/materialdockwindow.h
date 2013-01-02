#ifndef MATERIALDOCKWINDOW_H
#define MATERIALDOCKWINDOW_H

#include <QMainWindow>

namespace Ui {
class MaterialDockWindow;
}

class MaterialDockWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MaterialDockWindow(QWidget *parent = 0);
    ~MaterialDockWindow();

private slots:
    void on_btnBorrarBusqueda_pressed();

    void on_btnBuscar_pressed();
    void LibrarySaved();
private:
    void LoadMateriales(QString &filter);
private:
    Ui::MaterialDockWindow *ui;
};

#endif // MATERIALDOCKWINDOW_H
