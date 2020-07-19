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
		cout << "Failed to start Winsock" << wsOk;
		return -1;
	}

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	server.sin_addr.S_un.S_addr = ADDR_ANY;
	server.sin_family = AF_INET;
	server.sin_port = htons(54000);
	
	int result = ::bind(sockfd, (sockaddr*)&server, sizeof(server));
	if ( result == SOCKET_ERROR)
	{
		cout << "Failed to bind socket" << WSAGetLastError() << endl;
		return -1;
	}
	if (select(1, &fds, (fd_set*)0, (fd_set*)0, (struct timeval*)0)) { //Works one time
		mainWindow.getFile();
	}
	return app.exec();

	// Close socket
	closesocket(sockfd);

	// Shutdown winsock
	WSACleanup();

	

	
}