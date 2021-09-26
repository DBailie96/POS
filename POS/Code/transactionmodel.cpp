#include "transactionmodel.h"

TransactionModel::TransactionModel()
{

}

int TransactionModel::rowCount(const QModelIndex &parent) const
{
    return transactionList.size();
}

int TransactionModel::columnCount(const QModelIndex &parent) const
{
    return 7;
}

QVariant TransactionModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        int col = index.column();
        int row = index.row();
        switch(col)
        {
            case 0: return transactionList.at(row)->getId();            break;
            case 1: return transactionList.at(row)->getType();          break;
            case 2: return transactionList.at(row)->getInvoiceNumber(); break;
            case 3: return transactionList.at(row)->getBarcode();       break;
            case 4: return transactionList.at(row)->getQty();           break;
            case 5: return transactionList.at(row)->getPrice();         break;
            case 6: return transactionList.at(row)->getTimestamp();     break;
        }
    }
    return QVariant();
}

QVariant TransactionModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Vertical)
        return QVariant();

    switch (section)
    {
      case 0: return QString("Id");    break;
      case 1: return QString("Type");  break;
      case 2: return QString("Invoice Number");break;
      case 3: return QString("Barcode");   break;
      case 4: return QString("Quantity");      break;
      case 5: return QString("Price");      break;
      case 6: return QString("Time Stamp");      break;
      default: return QVariant();
    }

    return QVariant();
}

bool TransactionModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

}

void TransactionModel::update(Dbhandler *dbh)
{
    beginRemoveRows(QModelIndex(), 0, transactionList.size()-1);
    endRemoveRows();
    qDeleteAll(transactionList);
    transactionList.clear();

    transactionList = dbh->getAllTransactions();
    beginInsertRows(QModelIndex(), 0, transactionList.size()-1);
    endInsertRows();
}

TransactionModel::~TransactionModel()
{
    qDeleteAll(transactionList);
    transactionList.clear();
}
