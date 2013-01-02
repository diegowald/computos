#ifndef ANALYSISELEMENT_H
#define ANALYSISELEMENT_H

#include <QObject>
#include <QMap>
#include "analysisprovider.h"

namespace computo
{
namespace analysis
{

class AnalysisElement : public QObject
{
    Q_OBJECT
public:
    explicit AnalysisElement(QString nombreElemento, double cantidad, QObject *parent = 0);
    
    boost::shared_ptr<QStringList> getProvidersNames();
    AnalysisProvider *getProvider(QString provider);

    void compute();

    void clearSelectedPrices();
    void setSelectedPrice(QString nombreProveedor, QString nombreLista, QString nombrePrecio);
    void findBestPrice();
    double getBestPrice();
signals:
    
public slots:
    
private:
    QString elemento;
    double cantidadAComputar;
    QMap<QString, AnalysisProvider *> providers;

    QString mejorProveedor;
    QString mejorLista;
    QString mejorNombrePrecio;
    double mejorPrecio;

};

}}
#endif // ANALYSISELEMENT_H
