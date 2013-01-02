#include "wndbrowser.h"
#include "ui_wndbrowser.h"

wndBrowser::wndBrowser(QString search, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::wndBrowser)
{
    ui->setupUi(this);
    QString url = "https://www.google.com/search?q=%1";
    url = url.arg(search);
    ui->webView->stop();
    ui->webView->setUrl(QUrl(url));
    connect(ui->webView, SIGNAL(loadStarted()), this, SLOT(loadStarted()));
    connect(ui->webView, SIGNAL(loadProgress(int)), this, SLOT(loadProgress(int)));
    connect(ui->webView, SIGNAL(loadFinished(bool)), this, SLOT(loadFinished(bool)));
    setWindowTitle(url);
}

wndBrowser::~wndBrowser()
{
    delete ui;
}

void wndBrowser::loadStarted()
{
}

void wndBrowser::loadProgress(int)
{
}

void wndBrowser::loadFinished(bool)
{
}
