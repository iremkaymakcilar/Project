#include "mainwindow.h"
#include "ui_mainwindow.h"

#define SIZE 1024
sockaddr_in server;
SOCKET sockfd;
sockaddr_in client;
fd_set fds;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void  MainWindow::getFile() { //get file name from client
    char buf[SIZE];
    int clientLength = sizeof(client);
    ZeroMemory(&client, sizeof(client));
    ZeroMemory(buf, 1024);

    int bytesIn = recvfrom(sockfd, buf, SIZE, 0, (sockaddr*)&client, &clientLength);
    if (bytesIn == SOCKET_ERROR)
    {
        std::cout << "Error receiving message from client" << WSAGetLastError() << std::endl;
    }
    QString fileName(buf);
    onFileChanged();
}


void MainWindow::onFileChanged() { //add new tab and display the image
    ui->tabWidget->addTab(new QWidget(), "Image");
    QLabel label;
    QPixmap pixmap(fileName);
    label.setPixmap(pixmap);
    label.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
