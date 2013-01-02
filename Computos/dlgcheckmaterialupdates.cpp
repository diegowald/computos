#include "dlgcheckmaterialupdates.h"
#include "ui_dlgcheckmaterialupdates.h"

#include <QMessageBox>

#include <QDateTime>
#include <QMovie>
#include <QPixmap>
#include <QBitmap>

#include "datastore.h"
#include <QFile>

dlgCheckMaterialUpdates::dlgCheckMaterialUpdates(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgCheckMaterialUpdates)
{
    reply = NULL;
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    connect (manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(downloadFinished(QNetworkReply*)));
    url = "http://mksingenieria.com.ar/";
    URLupdate = url + "updates.dat";
    URLmaterialsFile = url + "materials.mat";
    materialsFile = "materials.mat";
    tmpFile = "materials.mat.tmp";
    bakFile = "materials.bak";
    ui->btnDownload->setEnabled(false);
    ui->btnInstall->setEnabled(false);
    QMovie *movie = new QMovie(":/dlg/dock/loader");
    //    ui->lblLoading->setWindowFlags(Qt::FramelessWindowHint);
    //ui->lblLoading->setMask((new QPixmap(":/dlg/dock/busy"))->mask());
    ui->lblStatus->clear();
    ui->lblLoading->setMovie(movie);
    movie->start();
    ui->lblLoading->setVisible(false);
}

dlgCheckMaterialUpdates::~dlgCheckMaterialUpdates()
{
    delete ui;
    delete manager;
    /*if (reply != NULL)
        delete reply;*/
}

void dlgCheckMaterialUpdates::on_btnCheck_clicked()
{
    reply = manager->get(QNetworkRequest(QUrl(URLupdate)));
    ui->buttonBox->setEnabled(false);
    ui->lblLoading->setVisible(true);
    ui->lblStatus->setText(tr("Checking updates..."));
}

void dlgCheckMaterialUpdates::on_btnDownload_pressed()
{
    reply = manager->get(QNetworkRequest(QUrl(URLmaterialsFile)));
    ui->lblLoading->setVisible(true);
    ui->lblStatus->setText(tr("Downloading new materials library..."));
}

void dlgCheckMaterialUpdates::on_btnInstall_pressed()
{
    ui->lblLoading->setVisible(true);
    ui->lblStatus->setText(tr("upgrading library"));
    QFile::copy(materialsFile, bakFile);
    QFile::copy(tmpFile, materialsFile);
    DataStore::getInstance()->getMaterialLibrary()->reload();
    ui->lblLoading->setVisible(false);
    ui->buttonBox->setEnabled(true);
}

void dlgCheckMaterialUpdates::downloadFinished(QNetworkReply *reply)
{
    QUrl url = reply->url();
    if (reply->error())
    {
        QMessageBox::warning(this,
                             tr("Material Update"),
                             tr("Cannot perform action.\n%1.").arg(reply->errorString()),
                             QMessageBox::Ok);
        return;
    }

    ui->lblLoading->setVisible(false);
    ui->lblStatus->clear();

    if (url.toString() == URLupdate)
        checkUpdate();
    else if(url.toString() == URLmaterialsFile)
        processDownload();
}

void dlgCheckMaterialUpdates::checkUpdate()
{
    QDataStream stream(reply);
    stream >> uv;

    if (uv.FechaUpdate() > DataStore::getInstance()->getMaterialLibrary()->getLastUpdate())
    {
        // Let's say everything is ok
        ui->btnDownload->setEnabled(true);
    }
    else
    {
        QMessageBox::warning(this,
                             tr("Check Materials updates"),
                             tr("Your materials library is up to date."),
                             QMessageBox::Ok | QMessageBox::Default);
        ui->lblStatus->setText(tr("Your materials library is up to date."));
    }
}

void dlgCheckMaterialUpdates::processDownload()
{
    if (reply->size() == uv.MaterialsFileLength())
    {
        QFile file(tmpFile);
        if (!file.open(QIODevice::WriteOnly))
        {
            // Error
            ui->lblStatus->setText(tr("There were errors processing download."));
            return;
        }
        file.write(reply->readAll());
        file.close();
        ui->btnInstall->setEnabled(true);
    }
    else
    {
        //qDebug() << reply->readAll();
        ui->lblStatus->setText(tr("There were errors processing download."));
    }
}
