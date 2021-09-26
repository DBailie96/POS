#include "stockmodel.h"

StockModel::StockModel()
{

}

int StockModel::rowCount(const QModelIndex &parent) const
{
    return stockList.size();
}

int StockModel::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant StockModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        int col = index.column();
        int row = index.row();
        switch(col)
        {
            case 0: return stockList.at(row)->getBarcode();     break;
            case 1: return stockList.at(row)->getItemCode();    break;
            case 2: return stockList.at(row)->getDescription(); break;
            case 3: return stockList.at(row)->getQty();         break;
            case 4: return stockList.at(row)->getPrice();       break;
        }
    }
    return QVariant();
}

QVariant StockModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Vertical)
        return QVariant();

    switch (section)
    {
      case 0: return QString("Barcode");    break;
      case 1: return QString("Item Code");  break;
      case 2: return QString("Description");break;
      case 3: return QString("Quantity");   break;
      case 4: return QString("Price");      break;
      default: return QVariant();
    }

    return QVariant();
}

bool StockModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

}

void StockModel::searchDB(QString searchTerm, Dbhandler *dbh)
{
    beginRemoveRows(QModelIndex(), 0, stockList.size());
    endRemoveRows();

    qDeleteAll(stockList);
    stockList.clear();

    stockList = dbh->searchRecords(searchTerm);
    beginInsertRows(QModelIndex(), 0, stockList.size());
    endInsertRows();
}


StockModel::~StockModel()
{
    qDeleteAll(stockList);
    stockList.clear();
}
