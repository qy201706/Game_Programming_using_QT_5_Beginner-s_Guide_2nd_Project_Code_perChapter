#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->startNewGame , &QPushButton::clicked , this , &MainWindow::startNewGame);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startNewGame()
{
    qDebug() << "button is clicked";
    ui->player1Name->setText(tr("qingyi"));
    ui->player2Name->setText(tr("kunjie"));
    ui->gameBoard->initgame();
}
