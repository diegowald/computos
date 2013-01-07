#ifndef PROYECTO_H
#define PROYECTO_H

#include <QObject>
#include <QMap>
#include <boost/shared_ptr.hpp>
#include "elementoconstructivo.h"
#include "author.h"
#include "xmlnode.h"
#include <boost/shared_ptr.hpp>
#include <pdfredlining.h>

namespace proyecto {

class Proyecto : public QObject
{
    Q_OBJECT
public:
    explicit Proyecto(QString filename, QObject *parent = 0);
    virtual ~Proyecto();
    
    void setNombre(QString Nombre);
    QString Nombre() const;

    void setPropietarios(QString Propietarios);
    QString Propietarios() const;

    void setDireccion(QString Direccion);
    QString Direccion() const;

    void setTelefono(QString Telefono);
    QString Telefono() const;

    void setEMail(QString EMail);
    QString EMail() const;

    void setNotas(QString Notas);
    QString Notas() const;

    void addElementoConstructivo(proyecto::ElementoConstructivo *elemento);
    proyecto::ElementoConstructivo *getElementoConstructivo(QString Name);
    boost::shared_ptr<QStringList> getAllElementoConstructivoNames();
    void removeElemento(QString Name);

    bool load(QString &filename);
    bool save();
    bool saveAs(QString &filename);

    boost::shared_ptr<QStringList> getValidExtensions();
private:

    bool saveAsStream(QString &filename);
    bool saveAsXML(QString &filename);
    bool loadFromStream(QString &filename);
    bool loadFromXML(QString &filename);
    bool loadProjectFromXMLTree(xml::XMLNode_ptr tree);
    xml::XMLNode_ptr createProjectXMLTree();


    Author *author;
    QString fileName;
    QString nombre;
    QString propietarios;
    QString direccion;
    QString telefono;
    QString email;
    QString notas;

    QMap<QString, proyecto::ElementoConstructivo*>elementosConstructivos;

    static QString objectName;
    static QString objectVersion;

    QMap<QString, pdf::PDFRedLining*> pdfs;
signals:

public slots:

public:
    static QString PROJECT_TAG;
    static QString NAME_TAG;
    static QString OWNER_TAG;
    static QString ADDRESS_TAG;
    static QString TELEPHONE_TAG;
    static QString EMAIL_TAG;
    static QString NOTES_TAG;
    static QString ELEMENTS_TAG;
    static QString COUNT_TAG;
};
}
#endif // PROYECTO_H
