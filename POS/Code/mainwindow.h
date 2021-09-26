#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "stockmodel.h"
#include "transactionmodel.h"
#include "transaction.h"
#include "dbhandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void searchClicked();
    void addItem();
    void checkStock();
    void updatePrices();
    void updateChange();
    void completeTransaction();
    void clear();
    void voidOne();
    void voidAll();
    void updateTransactionModel();

private:
    QString bcode;
    double price;
    int qty;

    StockModel *stockModel;
    TransactionModel *transactionModel;
    Dbhandler *dbhandler;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
