#include "setting.h"
#include "mainwindow.h"

int clientSocket;

void client_connecting()
{
    sockaddr_in clientAdress;
    socklen_t clientAdressSize = sizeof(clientAdress);
    std::thread t1(accept_connections,serverSocket,clientAdress,clientAdressSize);
    t1.detach();
}

void accept_connections(int serverSocket,sockaddr_in clientAdress,socklen_t clientAdressSize)
{    
    clientSocket = accept(serverSocket, (sockaddr*) &clientAdress, &clientAdressSize);
    std::cout << "Client connected" << std::endl;
    statusOfConnection = 2;
    //set_settings_server();
}
