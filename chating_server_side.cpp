#include "mainwindow.h"
#include "setting.h"

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

void MainWindow::recive_messege_like_a_server()
{
    char buffer[1024] = {0};
    while(true)
    {
        if(statusOfConnection == 2){
            int bytesReceived = recv(clientSocket, buffer, 1024, 0);
            if (bytesReceived < 0)
            {
                std::cerr << "Error: " << strerror(errno) << std::endl;
            }else if (bytesReceived == 0)
            {
                std::cout << "Client disconnected " << std::endl;
                //clientConnecting(serverSocket);
            }else
            {
                std::cout<<"recived"<<std::endl;
                QMetaObject::invokeMethod(this, "write_text_to_chat_history_reciving", Qt::QueuedConnection, Q_ARG(std::string, buffer));
            }
            memset(buffer, 0, sizeof(buffer));
        }

    }

}
