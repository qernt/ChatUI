#include "setting.h"
#include "ui_setting.h"

int statusOfConnection = 0;

setting::setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);

    ui->label_host_ip->setText(callIp());
    statusOfConnection = 0;

}

setting::~setting()
{
    delete ui;
}

void setting::on_pushButton_start_server_clicked()
{
    create_server(ui->textEdit_host_port->toPlainText().toInt());
}

void setting::show_status_of_connection(QString str)
{
    ui->label_server_status->setText(str);
}

void setting::on_pushButton_connect_clicked()
{
    connect_to_server(ui->textEdit_ip_to_connect->toPlainText().toStdString(),ui->textEdit_port_to_connect->toPlainText().toInt());
}





