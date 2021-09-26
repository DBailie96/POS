#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QObject>
#include <QDateTime>

class Transaction : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId);
    Q_PROPERTY(QString type READ getType WRITE setType);
    Q_PROPERTY(QString invoiceNumber READ getInvoiceNumber WRITE setInvoiceNumber);
    Q_PROPERTY(QString barcode READ getBarcode WRITE setBarcode);
    Q_PROPERTY(int qty READ getQty WRITE setQty);
    Q_PROPERTY(double price READ getPrice WRITE setPrice);
    Q_PROPERTY(QString timestamp READ getTimestamp WRITE setTimestamp);
public:
    explicit Transaction(QObject *parent = nullptr);
    Transaction(int i, QString t, QString inv, QString b, int q, double p, QString ts);

    void setId(int i);
    void setType(QString t);
    void setInvoiceNumber(QString inv);
    void setBarcode(QString b);
    void setQty(int q);
    void setPrice(double p);
    void setTimestamp(QString ts);

    int getId();
    QString getType();
    QString getInvoiceNumber();
    QString getBarcode();
    int getQty();
    double getPrice();
    QString getTimestamp();
signals:

private:
    int id;
    QString type;
    QString invoiceNumber;
    QString barcode;
    int qty;
    double price;
    QString timestamp;

};

#endif // TRANSACTION_H
