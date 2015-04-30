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

private:
    void setSplitterSizes();
    bool checkBeforeSend(QString &errStr);
    bool sendRequest();
    bool isPrevRowEmpty(int row);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
