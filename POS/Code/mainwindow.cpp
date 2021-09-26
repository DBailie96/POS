#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    stockModel = new StockModel;
    transactionModel = new TransactionModel;
    dbhandler = new Dbhandler;

    ui->setupUi(this);

    updateTransactionModel();
    ui->isDebit->setChecked(true);

    connect(ui->searchButton, SIGNAL(clicked()), this, SLOT(searchClicked()));
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addItem()));
    connect(ui->stockButton, SIGNAL(clicked()), this, SLOT(checkStock()));

    connect(ui->discountInput, SIGNAL(textChanged(QString)), this, SLOT(updatePrices()));
    connect(ui->tenderedInput, SIGNAL(textChanged(QString)), this, SLOT(updateChange()));

    connect(ui->completeButton, SIGNAL(clicked()), this, SLOT(completeTransaction()));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clear()));

    connect(ui->voidButton, SIGNAL(clicked()), this, SLOT(voidOne()));
    connect(ui->voidAllButton, SIGNAL(clicked()), this, SLOT(voidAll()));


    ui->searchView->setModel(stockModel);
    ui->transactionView->setModel(transactionModel);

    ui->searchView->resizeRowsToContents();
    ui->transactionView->resizeRowsToContents();
}

void MainWindow::searchClicked()
{
    stockModel->searchDB(ui->searchInput->text(), dbhandler);
    ui->searchView->update();
}

void MainWindow::addItem()
{
    bcode = ui->barcodeInput->text();

    if(dbhandler->validate(bcode))
    {
        qty = dbhandler->checkStock(bcode);

        if(ui->qtyEdit->value()<qty)
        {
            price = dbhandler->getPrice(bcode);
            double total = ui->qtyEdit->value()*price;

            ui->totalLabel->setText(QString("%1").arg(total));
            updatePrices();
        }
        else
        {
            QMessageBox msg;
            msg.setText("Not enough items in stock");
            msg.exec();
        }

    }
    else
    {
        QMessageBox msg;
        msg.setText("No item with this barcode found");
        msg.exec();
    }
}

void MainWindow::checkStock()
{
    QString bc = ui->barcodeInput->text();

    if(dbhandler->validate(bc))
    {
        int q = dbhandler->checkStock(bc);
        QMessageBox msg;
        msg.setText(QString("Items in stock: %1").arg(q));
        msg.exec();

    }
    else
    {
        QMessageBox msg;
        msg.setText("No item with this barcode found");
        msg.exec();
    }
}

void MainWindow::updatePrices()
{
    double totalPrice = ui->totalLabel->text().toDouble();
    double disc = 1-(ui->discountInput->text().toDouble()/100);
    double finalPrice;
    if(disc==0)
    {
        finalPrice = totalPrice;
    }
    else
    {
        finalPrice = totalPrice*disc;
    }
    ui->finalPriceLabel->setText(QString("%1").arg(finalPrice));

    updateChange();
}

void MainWindow::updateChange()
{
    double change = ui->tenderedInput->text().toDouble() - ui->finalPriceLabel->text().toDouble();
    ui->changeLabel->setText(QString("%1").arg(change));
}

void MainWindow::completeTransaction()
{
    double total = ui->totalLabel->text().toDouble();
    double change = ui->changeLabel->text().toDouble();

    if(!(total==0)||!(ui->totalLabel->text()==""))
    {
        if(change<0)
        {
            QMessageBox msg;
            msg.setText("Insufficient payment");
            msg.exec();
        }
        else
        {
            int deduced = ui->qtyEdit->value();
            dbhandler->updateQty(bcode, deduced);

            double final = ui->finalPriceLabel->text().toDouble();

            QString type;
            if(ui->isDebit->isChecked())
            {
                type = "debit";
            }
            else
            {
                type = "credit";
            }

            QString time = QDateTime::currentDateTime().toString();

            dbhandler->addTransaction(type, bcode, deduced, final, time);

            updateTransactionModel();

            clear();
        }
    }
}

void MainWindow::voidOne()
{
    QItemSelectionModel *select = ui->transactionView->selectionModel();
    int index = select->currentIndex().data().toInt();
    dbhandler->removeTransaction(index);
    updateTransactionModel();
}

void MainWindow::voidAll()
{
    dbhandler->removeAllTransactions();
    updateTransactionModel();
}

void MainWindow::updateTransactionModel()
{
    transactionModel->update(dbhandler);
    ui->transactionView->resizeRowsToContents();
}

void MainWindow::clear()
{
    price = 0;
    qty = 0;
    bcode = "";
    ui->qtyEdit->setValue(0);
    ui->tenderedInput->setText("");
    ui->discountInput->setText("");
    ui->totalLabel->setText("");
    updatePrices();
}

MainWindow::~MainWindow()
{
    delete dbhandler;
    delete stockModel;
    delete transactionModel;
    delete ui;
}
