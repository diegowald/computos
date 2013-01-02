#ifndef UPDATEVALIDATOR_H
#define UPDATEVALIDATOR_H

#include <QObject>
#include <QDateTime>
#include <fileheader.h>

class UpdateValidator : public QObject
{
    Q_OBJECT
public:
    explicit UpdateValidator(int fileLength, QDateTime updateDate, QObject *parent = 0);
    explicit UpdateValidator(QObject *parent = 0);
    QDateTime FechaUpdate();
    int MaterialsFileLength();

    friend QDataStream &operator <<(QDataStream &stream, const UpdateValidator &uv)
    {
        stream << uv.fechaUpdate;
        QString aux(QString::number(uv.materialsFileLength));
        stream << aux;
        return stream;
    }

    friend QDataStream &operator >>(QDataStream &stream, UpdateValidator &uv)
    {
        stream >> uv.fechaUpdate;
        QString aux;
        stream >> aux;
        uv.materialsFileLength = aux.toInt();
        return stream;
    }

signals:
    
public slots:
    
private:
    QDateTime fechaUpdate;
    int materialsFileLength;
};

#endif // UPDATEVALIDATOR_H
