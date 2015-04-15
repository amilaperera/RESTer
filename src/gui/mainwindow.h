#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    void setSplitterSizes();
    bool checkBeforeSend(QString &errStr);
    bool sendRequest();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
