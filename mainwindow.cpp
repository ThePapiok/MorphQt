#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    ui->widget->dylatacja();
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->widget->erozja();
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->widget->otwarcie();
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->widget->domkniecie();
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->widget->setValue(value);
}

