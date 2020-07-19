#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QFileDialog>
#include <iostream>
#include <QMessageBox>
#include <String>

sockaddr_in server;
SOCKET sockfd;

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    QObject::connect(ui->browseImageButton, SIGNAL(clicked()), this, SLOT(on_browseImageButton_clicked()));*/ //This causes buttons to work twice when pressed.
}

void MainWindow::on_browseImageButton_clicked() { //Browse Image button
        fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open Image"),
        "C:://",
        "*.jpeg");
    //QMessageBox::information(this,tr("File Name"), fileName);
    //fileName = "hello world";
}

void MainWindow::on_pushButton_clicked() { //Send button
    int send;
    //std::cout << fileName.toStdString() << std::endl;
    QByteArray arr = fileName.toLocal8Bit();
    std::string buf = arr.toStdString();
    //std::cout << buf << std::endl;
    /*char* buffer = "Hello World";
    */
    std::cout << buf << std::endl;
    send = sendto(sockfd, buf.c_str(), buf.size()+1, 0, (sockaddr*)&server, sizeof(server));
    if (send == SOCKET_ERROR)
    {
        std::cout << "Failed" << WSAGetLastError() << std::endl;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
