#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    ui->tabWidgetHistoryVSplitter->setSizes(QList<int> () << 200 << 75);
}
