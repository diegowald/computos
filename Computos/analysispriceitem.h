#ifndef ANALYSISPRICEITEM_H
#define ANALYSISPRICEITEM_H

#include <QObject>
#include "listaprecios.h"

namespace computo
{
namespace analysis
{

class AnalysisPriceItem : public QObject
{
    Q_OBJECT
public:
    explicit AnalysisPriceItem(listaPrecios::Precio *precio, double Quantity, QObject *parent = 0);
    QString getBrand();
    double getCalculatedQuantity();
    QString getCalculationUnit();
    double getBuyQuantity();
    QString getBuyUnit();
    double getRelation();
    double getPrice();

    bool isSelectedPrice() const;
    void clearSelectedPrice();
    void selectAsBestPrice();

    void compute();

signals:
    
public slots:
    
private:
    listaPrecios::Precio *srcPrecio;
    double quantity;

    double buyQuantity;
    double price;
    bool selectedPrice;
};

}}
#endif // ANALYSISPRICEITEM_H
