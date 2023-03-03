#include "setting.h"
#include "mainwindow.h"

int userSocket = 0;

void setting::connect_to_server(std::string ipAdress,int portNumber)
{
    userSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(userSocket == -1)
    {
        std::cerr << "Error of creatig socket" << std::endl;
        return;
    }

    sockaddr_in serverAdress;
    serverAdress.sin_family = AF_INET;
    serverAdress.sin_addr.s_addr = inet_addr(ipAdress.c_str());
    serverAdress.sin_port = htons(portNumber);

    if(::connect(userSocket, (sockaddr*)&serverAdress, sizeof(serverAdress)) < 0)
    {
        std::cout << "Error" << std::endl;
        return;
    }else
    {
        statusOfConnection = 4;
        show_status_of_connection("Have been connected");
    }
}
