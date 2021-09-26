#ifndef TRANSACTIONMODEL_H
#define TRANSACTIONMODEL_H

#include <QAbstractTableModel>
#include "transaction.h"
#include "dbhandler.h"

class TransactionModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    TransactionModel();
    ~TransactionModel();
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    void update(Dbhandler *dbh);
private:
    QList<Transaction*> transactionList;
};

#endif // TRANSACTIONMODEL_H
