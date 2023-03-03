#ifndef SETTING_H
#define SETTING_H

#include <QDialog>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>

namespace Ui {
class setting;
}

class setting : public QDialog
{
    Q_OBJECT

public:
    explicit setting(QWidget *parent = nullptr);
    ~setting();

    void show_status_of_connection(QString str);

    void create_server(int serverPort);

    void connect_to_server(std::string ipAdress,int portNumber);

    void deactivate_poles();

    void activate_poles();

private slots:
    void on_pushButton_start_server_clicked();

    void on_pushButton_connect_clicked();

    void on_pushButton_set_username_clicked();

private:
    Ui::setting *ui;


};

extern int statusOfConnectionForCheck;
extern int statusOfConnection; // 0 - username is not set up
                               // 1 - (server - server not started)(client - no connection to server)
                               // 2 - (server - server is started but client is not connected)
                               // 3 - (server - server is started and client is connected)
                               // 4 - (client - is connected to server)

QString callIp();

void client_connecting();
void accept_connections(sockaddr_in clientAdress,socklen_t clientAdressSize);
void client_connecting();

extern int clientSocket;
extern int serverSocket;
extern int userSocket;

extern std::string username;

#endif // SETTING_H
