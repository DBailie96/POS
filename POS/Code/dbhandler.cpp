#include "dbhandler.h"

Dbhandler::Dbhandler(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QODBC");

    QFile config("config.txt");
    if(!config.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QString address;

    QTextStream instream(&config);
    while(!instream.atEnd())
    {
        address = instream.readLine();
    }

    address = QDir::toNativeSeparators(address);

    QString connection = QString("Driver={SQL Server};Server=%1;Database=MYDB;Trusted_Connection=Yes;").arg(address);

    db.setDatabaseName(connection);

    db.open();
}

QList<StockItem*> Dbhandler::searchRecords(QString searchTerm)
{
    QList<StockItem*> tempList;

    QSqlQuery query(db);
    query.prepare("SELECT code, description, barcode, qty, price FROM Stock WHERE code=? OR description LIKE ?");
    query.bindValue(0, searchTerm);
    QString desc = "%" + searchTerm +"%";
    query.bindValue(1, desc);
    query.exec();

    while(query.next())
    {
        QString c = query.value(0).toString();
        QString d = query.value(1).toString();
        QString b = query.value(2).toString();
        int q = query.value(3).toInt();
        double p = query.value(4).toDouble();
        StockItem *temp;
        temp = new StockItem(b, c, d, q, p);
        tempList.append(temp);
    }

    return tempList;
}


bool Dbhandler::validate(QString b)
{
    QSqlQuery query(db);
    query.prepare("SELECT barcode FROM Stock WHERE barcode=?");
    query.bindValue(0, b);
    query.exec();
    query.first();
    if(query.isValid())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Dbhandler::checkStock(QString b)
{
    QSqlQuery query(db);
    query.prepare("SELECT qty FROM Stock WHERE barcode=?");
    query.bindValue(0, b);
    query.exec();
    query.first();

    return query.value(0).toInt();
}

double Dbhandler::getPrice(QString b)
{
    QSqlQuery query(db);
    query.prepare("SELECT price FROM Stock WHERE barcode=?");
    query.bindValue(0, b);
    query.exec();
    query.first();

    return query.value(0).toDouble();
}

void Dbhandler::updateQty(QString b, int q)
{
    QSqlQuery query(db);
    query.prepare("UPDATE Stock SET qty = (qty - ?) WHERE barcode=?");
    query.bindValue(0, q);
    query.bindValue(1, b);
    query.exec();

}

void Dbhandler::addTransaction(QString t, QString b, int q, double p, QString ts)
{
    QSqlQuery query(db);
    //query.prepare("INSERT INTO Transactions (transactionno, type, barcode, qty, price, timestamp) VALUES(NEXT VALUE FOR transaction_seq, ?, ?, ?, ?, ?)");
    query.prepare("INSERT INTO Transactions (type, barcode, qty, price, timestamp) VALUES(?, ?, ?, ?, ?)");
    query.bindValue(0, t);
    query.bindValue(1, b);
    query.bindValue(2, q);
    query.bindValue(3, p);
    query.bindValue(4, ts);
    query.exec();
}

QList<Transaction*> Dbhandler::getAllTransactions()
{
    QList<Transaction*> tempList;

    QSqlQuery query(db);
    query.prepare("SELECT * FROM Transactions");
    query.exec();


    while(query.next())
    {
        int id = query.value(0).toInt();
        QString type = query.value(1).toString();
        QString inv = query.value(2).toString();
        QString barcode = query.value(3).toString();
        int quantity = query.value(4).toInt();
        double price = query.value(5).toDouble();
        QString timestamp = query.value(6).toString();

        Transaction *tempTransaction = new Transaction(id, type, inv, barcode, quantity, price, timestamp);
        tempList.append(tempTransaction);
    }

    return tempList;
}

void Dbhandler::removeTransaction(int index)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM Transactions WHERE transactionno=?");
    query.bindValue(0, index);
    query.exec();
}

void Dbhandler::removeAllTransactions()
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM Transactions");
    query.exec();
}

Dbhandler::~Dbhandler()
{
    db.close();
}
