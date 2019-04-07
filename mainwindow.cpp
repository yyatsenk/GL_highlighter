#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "highlighter.h"

#define WIDTH   355
#define HEIGHT  312

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    searchHighLight = new SearchHighLight(ui->textEdit->document());

    this->setFixedWidth(WIDTH);
    this->setFixedHeight(HEIGHT);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onSearchText);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete searchHighLight;
}

void MainWindow::onSearchText()
{
    searchHighLight->searchText(ui->textEdit->toPlainText(), ui->lineEdit->text());
}
