#include "mainwindow.h"
#include "setting.h"

void MainWindow::send_messege_like_a_client()
{
    std::string messegeToSend = messege_to_send();
    std::string fullMessage = username + ": " + messegeToSend;

    if(messegeToSend != "")
    {
        if(send(userSocket, fullMessage.c_str(), fullMessage.length(), 0) < 0)
        {
            std::cerr << "Error of sending";
            return ;
        }
    }
}

void MainWindow::recive_messege_like_a_client()
{
    char buffer[1024] = {0};
    while(true)
    {
        if(statusOfConnection == 4)
        {
            int bytesRecived = recv(userSocket, buffer, 1024, 0);
            if (bytesRecived < 0)
            {
                std::cerr << "Error: " << strerror(errno) << std::endl;
            }else if (bytesRecived == 0)
            {
                std::cout << "Client disconnected " << std::endl;
                statusOfConnection = 0;
            }else
            {
                QMetaObject::invokeMethod(this, "write_text_to_chat_history_reciving", Qt::QueuedConnection, Q_ARG(std::string, buffer));
            }
        }
        memset(buffer, 0, sizeof(buffer));
    }
}
