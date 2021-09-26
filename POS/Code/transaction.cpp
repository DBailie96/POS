#include "transaction.h"

Transaction::Transaction(QObject *parent) : QObject(parent)
{

}

Transaction::Transaction(int i, QString t, QString inv,
                         QString b, int q, double p, QString ts): id(i), type(t), invoiceNumber(inv),
                            barcode(b), qty(q), price(p), timestamp(ts)
{

}

void Transaction::setId(int i)
{
    id = i;
}

void Transaction::setType(QString t)
{
    type = t;
}

void Transaction::setInvoiceNumber(QString inv)
{
    invoiceNumber = inv;
}

void Transaction::setBarcode(QString b)
{
    barcode = b;
}

void Transaction::setQty(int q)
{
    qty = q;
}

void Transaction::setPrice(double p)
{
    price = p;
}

void Transaction::setTimestamp(QString ts)
{
    timestamp = ts;
}

int Transaction::getId()
{
    return id;
}

QString Transaction::getType()
{
    return type;
}

QString Transaction::getInvoiceNumber()
{
    return invoiceNumber;
}

QString Transaction::getBarcode()
{
    return barcode;
}

int Transaction::getQty()
{
    return qty;
}

double Transaction::getPrice()
{
    return price;
}

QString Transaction::getTimestamp()
{
    return timestamp;
}
