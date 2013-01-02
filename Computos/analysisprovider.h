#ifndef ANALYSISPROVIDER_H
#define ANALYSISPROVIDER_H

#include <QObject>
#include <QMap>
#include <boost/shared_ptr.hpp>
#include "analysispricelist.h"
#include "elementoconstructivo.h"

namespace computo
{
namespace analysis
{

class AnalysisProvider : public QObject
{
    Q_OBJECT
public:
    explicit AnalysisProvider(QString elemento, double cantidadCalculada, QString proveedor, QObject *parent = 0);
    boost::shared_ptr<QStringList> getListas();
    AnalysisPriceList *getLista(QString nombreLista);

    void compute();
    void clearSelectedPrices();
    void setSelectedPrice(QString nombreLista, QString nombreElemento);
    void findBestPrice(QString &Lista, QString &NombrePrecio, double &Precio);
signals:
    
public slots:
    
private:
    QString nombreElemento;
    QString nombreProveedor;
    QMap<QString, AnalysisPriceList*> listas;
};

}}
#endif // ANALYSISPROVIDER_H
