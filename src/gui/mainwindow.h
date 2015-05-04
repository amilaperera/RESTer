#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_sendToolBtn_clicked();

    void on_addHeaderToolBtn_clicked();

    void on_rqstHeadersTableWidget_itemChanged(QTableWidgetItem *item);

    void on_removeHeaderToolBtn_clicked();

    void on_moveUpHeaderToolBtn_clicked();

    void on_moveDownHeaderToolBtn_clicked();

private:
    enum MoveDirection { Down, Up };

private:
    void setSplitterSizes();
    void setRqstHeadersTableWidgetProperties();
    bool checkBeforeSend(QString &errStr);
    bool sendRequest();
    bool isPrevRowEmpty(int row);
    QList<QTableWidgetItem *> takeRow(QTableWidget *tblWidget, int row);
    void setRow(QTableWidget *tblWidget, int row, QList<QTableWidgetItem *>& rowItems);
    void moveRow(QTableWidget *tblWidget, MoveDirection dir = MoveDirection::Up);
    bool canMoveRow(QTableWidget *tblWidget, int currentIndex, MoveDirection dir = MoveDirection::Up);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
