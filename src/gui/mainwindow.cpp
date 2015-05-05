#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

#define HEADER_NAME_COLUMN                       0
#define HEADER_VALUE_COLUMN                      1

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setSplitterSizes();
    setRqstHeadersTableWidgetProperties();
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

void MainWindow::setRqstHeadersTableWidgetProperties()
{
    ui->rqstHeadersTableWidget->verticalHeader()->setVisible(false);
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
        QTableWidgetItem *hName = ui->rqstHeadersTableWidget->item(row - 1,
                                                                   HEADER_NAME_COLUMN);
        QTableWidgetItem *hValue = ui->rqstHeadersTableWidget->item(row - 1,
                                                                    HEADER_VALUE_COLUMN);
        // we check if the header name of the previous header is not written
        // or if it is empty
        if (!hName || (hName && hName->text().trimmed().isEmpty())) {
            if (hValue)
                hValue->setText("");
            return true;
        }
    }
    return false;
}

QList<QTableWidgetItem *> MainWindow::takeRow(QTableWidget *tblWidget, int row)
{
    QList<QTableWidgetItem *> rowItems;
    for (int col = 0; col < tblWidget->columnCount(); ++col)
        rowItems << tblWidget->takeItem(row, col);

    return rowItems;
}

void MainWindow::setRow(QTableWidget *tblWidget, int row, QList<QTableWidgetItem *> &rowItems)
{
    for (int col = 0; col < tblWidget->columnCount(); ++col)
        tblWidget->setItem(row, col, rowItems.at(col));
}

// TODO: row moving when multiple rows are selected
void MainWindow::moveRow(QTableWidget *tblWidget, MoveDirection dir)
{
    QItemSelectionModel *selectionModel = ui->rqstHeadersTableWidget->selectionModel();
    QModelIndex currentIndex = ui->rqstHeadersTableWidget->currentIndex();
    bool isCurrentItemSelected = selectionModel->isSelected(currentIndex);

    if (isCurrentItemSelected && currentIndex.isValid()) {
        int sourceRow = tblWidget->row(tblWidget->selectedItems().at(0));
        if (canMoveRow(tblWidget, sourceRow, dir)) {
            int destRow = dir == MoveDirection::Up ? sourceRow - 1 : sourceRow + 1;

            QList<QTableWidgetItem *> sourceItems = takeRow(tblWidget, sourceRow);
            QList<QTableWidgetItem *> destItems = takeRow(tblWidget, destRow);

            setRow(tblWidget, sourceRow, destItems);
            setRow(tblWidget, destRow, sourceItems);

            tblWidget->setCurrentCell(destRow, 0);
        }
    }
}

bool MainWindow::canMoveRow(QTableWidget *tblWidget, int currentIndex, MoveDirection dir)
{
    // if moving up when @ 0th row ||
    //    moving down when @ last row ||
    //    current row goes out of range of the current table
    // then, we can't move
    if ((dir == MoveDirection::Up && currentIndex == 0) ||
        (dir == MoveDirection::Down && currentIndex == tblWidget->rowCount() - 1) ||
        (currentIndex < 0 || currentIndex > tblWidget->rowCount() - 1))
        return false;

    return true;
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
    if (!isPrevRowEmpty(row)) {
        ui->rqstHeadersTableWidget->insertRow(row);
        ui->rqstHeadersTableWidget->setRowHeight(row, 20);
    }
}

void MainWindow::on_rqstHeadersTableWidget_itemChanged(QTableWidgetItem *item)
{
    if (item)
        item->setText(item->text().trimmed());
}

void MainWindow::on_removeHeaderToolBtn_clicked()
{
    QItemSelectionModel *selectionModel = ui->rqstHeadersTableWidget->selectionModel();
    QModelIndex currentIndex = ui->rqstHeadersTableWidget->currentIndex();
    bool isCurrentItemSelected = selectionModel->isSelected(currentIndex);

    if (isCurrentItemSelected && currentIndex.isValid())
            ui->rqstHeadersTableWidget->removeRow(ui->rqstHeadersTableWidget->currentRow());
}

void MainWindow::on_moveUpHeaderToolBtn_clicked()
{
    moveRow(ui->rqstHeadersTableWidget, MoveDirection::Up);
}

void MainWindow::on_moveDownHeaderToolBtn_clicked()
{
    moveRow(ui->rqstHeadersTableWidget, MoveDirection::Down);
}
