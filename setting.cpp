#include "setting.h"
#include "ui_setting.h"

int statusOfConnection = 0;
int statusOfConnectionForCheck = 0;

std::string username = "";

setting::setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);

    this->setFixedSize(240, 400);
    this->setWindowTitle("Settings");

    ui->lineEdit_ip_to_connect->setInputMask("000.000.000.000;");
    ui->lineEdit_port_to_connect->setInputMask("0000000;");
    ui->lineEdit_host_port->setInputMask("0000000;");

    ui->label_host_ip->setText(callIp());
    statusOfConnection = 0;

    ui->pushButton_connect->setDisabled(true);
    ui->pushButton_start_server->setDisabled(true);
    ui->lineEdit_ip_to_connect->setReadOnly(true);
    ui->lineEdit_host_port->setReadOnly(true);
    ui->lineEdit_port_to_connect->setReadOnly(true);
}

setting::~setting()
{
    delete ui;
}

void setting::on_pushButton_start_server_clicked()
{
    create_server(ui->lineEdit_host_port->text().toInt());
    deactivate_poles();
}

void setting::show_status_of_connection(QString str)
{
    ui->label_server_status->setText(str);
}

void setting::on_pushButton_connect_clicked()
{
    connect_to_server(ui->lineEdit_ip_to_connect->text().toStdString(),ui->lineEdit_port_to_connect->text().toInt());
    deactivate_poles();
}

void setting::on_pushButton_set_username_clicked()
{
    std::string oldUsername = username;
    username = ui->lineEdit_username->text().toStdString();
    if(username != "")
    {
        statusOfConnection = 1;
        show_status_of_connection("Username has been set up");
        activate_poles();
    }else if(username != oldUsername && username != "")
    {
        show_status_of_connection("Username has been changed");
    }
}

void setting::deactivate_poles()
{
    if(statusOfConnection == 4 || statusOfConnection == 2)
    {
        ui->lineEdit_ip_to_connect->setReadOnly(true);
        ui->lineEdit_host_port->setReadOnly(true);
        ui->lineEdit_port_to_connect->setReadOnly(true);
        ui->pushButton_connect->setDisabled(true);
        ui->pushButton_start_server->setDisabled(true);
    }

}

void setting::activate_poles()
{
    if(statusOfConnection == 1)
    {
        ui->lineEdit_ip_to_connect->setReadOnly(false);
        ui->lineEdit_host_port->setReadOnly(false);
        ui->lineEdit_port_to_connect->setReadOnly(false);
        ui->pushButton_connect->setEnabled(true);
        ui->pushButton_start_server->setEnabled(true);
    }

}





