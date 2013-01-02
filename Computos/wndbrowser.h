#ifndef WNDBROWSER_H
#define WNDBROWSER_H

#include <QMainWindow>

namespace Ui {
class wndBrowser;
}

class wndBrowser : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit wndBrowser(QString search, QWidget *parent = 0);
    ~wndBrowser();
    
private:
    Ui::wndBrowser *ui;

private slots:
    void loadStarted();
    void loadProgress(int progress);
    void loadFinished(bool success);
};

#endif // WNDBROWSER_H
