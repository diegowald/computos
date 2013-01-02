#include "analysispriceitem.h"
#include "datastore.h"

namespace computo
{
namespace analysis
{

AnalysisPriceItem::AnalysisPriceItem(listaPrecios::Precio
                                     *precio, double Quantity, QObject *parent) :
    QObject(parent), srcPrecio(precio), quantity(Quantity)
{
    price = 0;
    buyQuantity = 0;
    selectedPrice = false;
}

QString AnalysisPriceItem::getBrand()
{
    return srcPrecio->Marca();
}

double AnalysisPriceItem::getCalculatedQuantity()
{
    return quantity;
}

QString AnalysisPriceItem::getCalculationUnit()
{
    return DataStore::getInstance()->getMaterialLibrary()->getElemento(
                srcPrecio->getNombreElemento())->getMeasureUnit()->getInternalName();
}

double AnalysisPriceItem::getBuyQuantity()
{
    return buyQuantity;
}

QString AnalysisPriceItem::getBuyUnit()
{
    return srcPrecio->getUnidadVenta()->getInternalName();
}

double AnalysisPriceItem::getRelation()
{
    return srcPrecio->Relacion();
}

double AnalysisPriceItem::getPrice()
{
    return price;
}

void AnalysisPriceItem::compute()
{
    buyQuantity = srcPrecio->calcularCantidadAComprar(quantity);
    price = srcPrecio->calcularPrecio(quantity);
}

bool AnalysisPriceItem::isSelectedPrice() const
{
    return selectedPrice;
}

void AnalysisPriceItem::clearSelectedPrice()
{
    selectedPrice = false;
}

void AnalysisPriceItem::selectAsBestPrice()
{
    selectedPrice = true;
}

}}
