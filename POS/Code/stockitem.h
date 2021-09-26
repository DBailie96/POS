#ifndef STOCKITEM_H
#define STOCKITEM_H

#include <QObject>

class StockItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString barcode READ getBarcode WRITE setBarcode)
    Q_PROPERTY(QString itemCode READ getItemCode WRITE setItemCode)
    Q_PROPERTY(QString description READ getDescription WRITE setDescription)
    Q_PROPERTY(int qty READ getQty WRITE setQty)
    Q_PROPERTY(double price READ getPrice WRITE setPrice);
public:
    explicit StockItem(QObject *parent = nullptr);
    StockItem(QString b, QString i, QString d, int q, double p);
    void setBarcode(QString b);
    void setItemCode(QString i);
    void setDescription(QString d);
    void setQty(int q);
    void setPrice(double p);
    QString getBarcode();
    QString getItemCode();
    QString getDescription();
    int getQty();
    double getPrice();
private:
    QString barcode;
    QString itemCode;
    QString description;
    int qty;
    double price;
};

#endif // STOCKITEM_H
