#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <QObject>
#include <boost/shared_ptr.hpp>
#include <QMap>
#include "analysiselement.h"
#include "analysisprovider.h"

namespace computo
{
namespace analysis
{

class Analysis : public QObject
{
    Q_OBJECT
public:
    explicit Analysis(QString projectName, QObject *parent = 0);

    void compute();
    boost::shared_ptr<QStringList> getProvidersNames(QString nombreElemento);
    AnalysisProvider *getProvider(QString nombreElemento, QString provider);
    double getTotalCost();

    void setSelectedPrice(QString nombreElemento, QString nombreProveedor, QString nombreLista, QString nombrePrecio);
signals:
    
public slots:

private:
    QString name;

    QMap<QString, AnalysisElement*> analysisElements;

    void clearSelectedPrices(QString nombreElemento);
    void findBestPrice(QString nombreElemento);

};

}}
#endif // ANALYSIS_H
