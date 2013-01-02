#ifndef DLGCHECKMATERIALUPDATES_H
#define DLGCHECKMATERIALUPDATES_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>

#include "updatevalidator.h"

namespace Ui {
class dlgCheckMaterialUpdates;
}

class dlgCheckMaterialUpdates : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgCheckMaterialUpdates(QWidget *parent = 0);
    ~dlgCheckMaterialUpdates();
    
private slots:
    void on_btnCheck_clicked();
    void on_btnDownload_pressed();
    void on_btnInstall_pressed();
    void downloadFinished(QNetworkReply *reply);
private:
    Ui::dlgCheckMaterialUpdates *ui;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;

    QString url;
    QString URLupdate;
    QString URLmaterialsFile;
    UpdateValidator uv;
    QString materialsFile;
    QString tmpFile;
    QString bakFile;

    void checkUpdate();
    void processDownload();
};

#endif // DLGCHECKMATERIALUPDATES_H
