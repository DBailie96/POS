#include "stockitem.h"

StockItem::StockItem(QObject *parent) : QObject(parent)
{

}

StockItem::StockItem(QString b, QString i, QString d, int q, double p): barcode(b), itemCode(i), description(d), qty(q), price(p)
{

}

QString StockItem::getBarcode()
{
    return barcode;
}

QString StockItem::getItemCode()
{
    return itemCode;
}

QString StockItem::getDescription()
{
    return description;
}

int StockItem::getQty()
{
    return qty;
}

double StockItem::getPrice()
{
    return price;
}

void StockItem::setBarcode(QString b)
{
    barcode = b;
}

void StockItem::setItemCode(QString i)
{
    itemCode = i;
}

void StockItem::setDescription(QString d)
{
    description = d;
}

void StockItem::setQty(int q)
{
    qty = q;
}

void StockItem::setPrice(double p)
{
    price = p;
}
