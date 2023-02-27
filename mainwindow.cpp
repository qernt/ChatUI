#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setting.h"
#include <QThread>

std::string username = "";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qRegisterMetaType<std::string>("std::string");

    ui->plainTextEdit_chat_history->setReadOnly(true);

    settingWindow = new setting();

    std::thread t(&MainWindow::recive_messege_like_a_server, this);
    t.detach();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_go_to_settings_clicked()
{
    settingWindow->show();
}


void MainWindow::on_pushButton_send_messege_clicked()
{
    if(statusOfConnection == 2)
    {
        write_text_to_chat_history_like_a_server_sending();
        send_messege_like_a_server();
    }else if(statusOfConnection == 3)
    {

    }
}

std::string MainWindow::messege_to_send()
{
    std::string messege = "";
    messege = ui->plainTextEdit_messege->toPlainText().toStdString();
    ui->plainTextEdit_messege->setPlainText("");
    return messege;
}

void MainWindow::on_pushButton_set_username_clicked()
{
    username = ui->plainTextEdit_2->toPlainText().toStdString();
}

void MainWindow::write_text_to_chat_history_like_a_server_sending()
{
    if(ui->plainTextEdit_chat_history->toPlainText() == "")
    {
        ui->plainTextEdit_chat_history->setPlainText(QString::fromStdString(username + ": " + ui->plainTextEdit_messege->toPlainText().toStdString() + "\n"));
    }else
    {
        ui->plainTextEdit_chat_history->setPlainText(QString::fromStdString(ui->plainTextEdit_chat_history->toPlainText().toStdString() + username + ": " + ui->plainTextEdit_messege->toPlainText().toStdString() + "\n"));
    }
}

void MainWindow::write_text_to_chat_history_reciving(std::string messege)
{
    if(ui->plainTextEdit_chat_history->toPlainText() == "")
    {
        ui->plainTextEdit_chat_history->setPlainText(QString::fromStdString(messege + "\n"));
    }else
    {
        ui->plainTextEdit_chat_history->setPlainText(QString::fromStdString(ui->plainTextEdit_chat_history->toPlainText().toStdString() + messege + "\n"));
    }
}
