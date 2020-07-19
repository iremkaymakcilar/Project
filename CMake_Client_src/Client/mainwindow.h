#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <WS2tcpip.h>
#include <QMainWindow>

extern sockaddr_in server;
extern SOCKET sockfd;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    QString fileName;

public slots:
    void on_pushButton_clicked(); //Sending image
    void on_browseImageButton_clicked(); //Browsing image

private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
