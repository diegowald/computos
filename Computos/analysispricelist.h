#ifndef ANALYSISPRICELIST_H
#define ANALYSISPRICELIST_H

#include <QObject>
#include <boost/shared_ptr.hpp>
#include <QMap>

#include "analysispriceitem.h"

namespace computo
{
namespace analysis
{

class AnalysisPriceList : public QObject
{
    Q_OBJECT
public:
    explicit AnalysisPriceList(QString elemento, double cantidadCalculada, QString proveedor, QString NombrelistaPrecios, QObject *parent = 0);
    boost::shared_ptr<QList<AnalysisPriceItem*> > getPrecios();
    AnalysisPriceItem *getPrecio(QString nombrePrecio);
    void compute();
    void clearSelectedPrices();
    void setSelectedPrice(QString nombrePrecio);
    void findBestPrice(QString &NombrePrecio, double &Precio);
signals:
    
public slots:
    
private:
    QString nombreElemento;
    QString nombreListaPrecios;
    QMap<QString, AnalysisPriceItem*> precios;
};

}}
#endif // ANALYSISPRICELIST_H
