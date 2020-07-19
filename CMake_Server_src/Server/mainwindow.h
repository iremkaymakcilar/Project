#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <WS2tcpip.h>
#include <QMainWindow>
#include <iostream>

extern sockaddr_in server;
extern SOCKET sockfd;
extern sockaddr_in client;
extern fd_set fds;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString fileName;
    void getFile();

private:
    Ui::MainWindow *ui;
public slots:
    void onFileChanged();
};

#endif // MAINWINDOW_H
