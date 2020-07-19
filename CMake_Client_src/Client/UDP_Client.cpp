#include <iostream>
#include <QApplication>
#include "mainwindow.h"

#pragma comment (lib, "ws2_32.lib")

using namespace std;

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	MainWindow mainWindow;
	mainWindow.show();

	WSADATA data;
	WORD version = MAKEWORD(2, 2);

	// Start WinSock
	int wsOk = WSAStartup(version, &data);
	if (wsOk != 0)
	{
		cout << "Failed to start Winsock! " << wsOk;
		return -1;
	}

	inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	server.sin_family = AF_INET;
	server.sin_port = htons(54000);

	return app.exec();
	
	// Close the socket
	closesocket(sockfd);

	// Shutdown Winsock
	WSACleanup();
}