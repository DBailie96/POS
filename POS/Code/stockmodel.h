#ifndef STOCKMODEL_H
#define STOCKMODEL_H

#include <QAbstractTableModel>
#include "stockitem.h"
#include "dbhandler.h"
#include <QDebug>

class StockModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    StockModel();
    ~StockModel();
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
public slots:
    void searchDB(QString searchTerm, Dbhandler *dbh);
private:
    QList<StockItem*> stockList;
};

#endif // STOCKMODEL_H
