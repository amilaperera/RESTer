#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setSplitterSizes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSplitterSizes()
{
    ui->rqstHeaderBodyHSplitter->setSizes(QList<int> () << 100 << 200);
    ui->respHeaderBodyHSplitter->setSizes(QList<int> () << 100 << 200);
    ui->tabWidgetHistoryVSplitter->setSizes(QList<int> () << 200 << 75);
}

bool MainWindow::checkBeforeSend(QString &errStr)
{
    errStr = "";
    QString urlText = ui->urlLineEdit->text().trimmed();
    if (urlText.isEmpty()) {
        errStr = "Url can not be empty.";
    }

    return errStr.isEmpty() ? true : false;
}

bool MainWindow::sendRequest()
{
    qDebug() << "request sending started";
    return true;
}

bool MainWindow::isPrevRowEmpty(int row)
{
    if (row > 0) {
        QTableWidgetItem *item0 = ui->rqstHeadersTableWidget->item(row - 1, 0);
        QTableWidgetItem *item1 = ui->rqstHeadersTableWidget->item(row - 1, 1);
    }
    return false;
}

void MainWindow::on_sendToolBtn_clicked()
{
    QString errStr;
    if (!checkBeforeSend(errStr)) {
        qDebug() << "error occured while checking parameters before sending request";
        QMessageBox::warning(this, "Error", errStr);
    } else {
        (void) sendRequest();
    }
}

void MainWindow::on_addHeaderToolBtn_clicked()
{
    int row = ui->rqstHeadersTableWidget->rowCount();
    if (!isPrevRowEmpty(row))
        ui->rqstHeadersTableWidget->insertRow(row);
}
