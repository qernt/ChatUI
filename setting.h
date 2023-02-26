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

private slots:
    void on_pushButton_start_server_clicked();

    void on_pushButton_connect_clicked();

public slots:
    void show_status_of_connection(QString str);

    void create_server(int serverPort);


private:
    Ui::setting *ui;
};

extern int statusOfConnection;

QString callIp();

void client_connecting(int serverSocket);
void accept_connections(int serverSocket,sockaddr_in clientAdress,socklen_t clientAdressSize);
void client_connecting(int serverSocket);
void connect_to_server(std::string ipAdress,int portNumber);
void set_settings_server(int client, int server);

#endif // SETTING_H
