#include "updatevalidator.h"

UpdateValidator::UpdateValidator(int fileLength, QDateTime updateDate, QObject *parent) :
    QObject(parent), fechaUpdate(updateDate), materialsFileLength(fileLength)
{
}

UpdateValidator::UpdateValidator(QObject *parent)
    : QObject(parent)
{
    fechaUpdate = QDateTime::currentDateTime();
    materialsFileLength = 0;
}

QDateTime UpdateValidator::FechaUpdate()
{
    return fechaUpdate;
}

int UpdateValidator::MaterialsFileLength()
{
    return materialsFileLength;
}
