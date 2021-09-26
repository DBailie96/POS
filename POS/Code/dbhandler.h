#ifndef DBHANDLER_H
#define DBHANDLER_H

#include <QObject>
#include <QtSql>
#include <QFileDialog>
#include "stockitem.h"
#include "transaction.h"

class Dbhandler : public QObject
{
    Q_OBJECT
public:
    explicit Dbhandler(QObject *parent = nullptr);
    ~Dbhandler();

    QList<StockItem*> searchRecords(QString searchTerm);
    bool validate(QString b);
    int checkStock(QString b);
    double getPrice(QString b);
    void updateQty(QString b, int q);
    void addTransaction(QString t, QString b, int q, double p, QString ts);
    void removeTransaction(int index);
    void removeAllTransactions();
    QList<Transaction*> getAllTransactions();
signals:

private:
    QSqlDatabase db;

};

#endif // DBHANDLER_H
