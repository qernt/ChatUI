#include "setting.h"
#include "ui_setting.h"

int statusOfConnection = 0;

setting::setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);

    this->setFixedSize(500, 185);
    this->setWindowTitle("Settings");

    ui->lineEdit_ip_to_connect->setInputMask("000.000.000.000;");
    ui->lineEdit_port_to_connect->setInputMask("0000;");
    ui->lineEdit_host_port->setInputMask("0000;");

    ui->label_host_ip->setText(callIp());
    statusOfConnection = 0;
}

setting::~setting()
{
    delete ui;
}

void setting::on_pushButton_start_server_clicked()
{
    create_server(ui->lineEdit_host_port->text().toInt());
}

void setting::show_status_of_connection(QString str)
{
    ui->label_server_status->setText(str);
}

void setting::on_pushButton_connect_clicked()
{
    connect_to_server(ui->lineEdit_ip_to_connect->text().toStdString(),ui->lineEdit_port_to_connect->text().toInt());
}





