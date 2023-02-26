#include "setting.h"

void setting::create_server(int serverPort)
{
    int serverSocket;
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSocket == -1)
    {
        show_status_of_connection("Error of creating socket");
        return;
    }

    sockaddr_in serverAdress;
    serverAdress.sin_family = AF_INET;
    serverAdress.sin_addr.s_addr = INADDR_ANY;
    serverAdress.sin_port = htons(serverPort);

    if(bind(serverSocket, (sockaddr*)&serverAdress, sizeof(serverAdress)) == -1)
    {
        show_status_of_connection("Error of bind to port");
        return;
    }

    if(listen(serverSocket, SOMAXCONN) == -1)
    {
        show_status_of_connection("Error listening on socket");
        return;
    }
    show_status_of_connection("Server is running");
    statusOfConnection = 1;
    client_connecting(serverSocket);
}
