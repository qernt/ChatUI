#include "mainwindow.h"
#include "setting.h"

int clientSocket = 0;
int serverSocket = 0;

void set_settings_server(int client, int server)
{
    clientSocket = client;
    serverSocket = server;
    //std::thread t1(&MainWindow::recive_messege_like_a_server,this);
    //t1.detach();
}

void MainWindow::send_messege_like_a_server()
{
    std::string messegeToSend = messege_to_send();
    std::string fullMessage = username + ": " + messegeToSend;
    if(messegeToSend != "")
    {
        if(send(clientSocket, fullMessage.c_str(), fullMessage.length(), 0) < 0)
        {
            std::cerr << "Error of sending";
            return;
        }
        fflush(stdout);
    }
}

/*void MainWindow::recive_messege_like_a_server()
{
    while(true)
        {
            char buffer[1024] = {0};
            while(true)
            {
                int bytesReceived = recv(clientSocket, buffer, 1024, 0);
                if (bytesReceived == 0)
                {
                    std::cout << "Client disconnected " << std::endl;
                    //clientConnecting(serverSocket);
                }else
                    write_text_to_chat_history_reciving(buffer);
                memset(buffer, 0, sizeof(buffer));
            }
        }
}*/
