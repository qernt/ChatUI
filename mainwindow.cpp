#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setting.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qRegisterMetaType<std::string>("std::string");

    this->setFixedSize(440,540);
    this->setWindowTitle("Chat");

    ui->plainTextEdit_chat_history->setReadOnly(true);

    ui->lineEdit_messege->setPlaceholderText("messege");

    settingWindow = new setting();

    std::thread t1(&MainWindow::recive_messege_like_a_server, this);
    std::thread t2(&MainWindow::recive_messege_like_a_client, this);
    t1.detach();
    t2.detach();
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
    if(statusOfConnection == 3 || statusOfConnection == 4)
    {
        write_text_to_chat_history_sending();
    }
    if(statusOfConnection == 3)
    {
        send_messege_like_a_server();
    }else if(statusOfConnection == 4)
    {
        send_messege_like_a_client();
    }else if(statusOfConnection == 0)
    {
        QMessageBox::warning(nullptr, "Error", "Username is not set up.");
        return;
    }else if(statusOfConnection == 1)
    {
        QMessageBox::warning(nullptr, "Error", "Server - Server not started \nClient - No connection to server.");
        return;
    }else if(statusOfConnection == 2)
    {
        QMessageBox::warning(nullptr, "Error", "Server is started but client is not connected.");
        return;
    }
}

std::string MainWindow::messege_to_send()
{
    std::string messege = "";
    messege = ui->lineEdit_messege->text().toStdString();
    ui->lineEdit_messege->setText("");
    return messege;
}

void MainWindow::write_text_to_chat_history_sending()
{
    if(ui->plainTextEdit_chat_history->toPlainText() == "")
    {
        ui->plainTextEdit_chat_history->setPlainText(QString::fromStdString(username + ": " + ui->lineEdit_messege->text().toStdString() + "\n"));
    }else
    {
        ui->plainTextEdit_chat_history->setPlainText(QString::fromStdString(ui->plainTextEdit_chat_history->toPlainText().toStdString() + username + ": " + ui->lineEdit_messege->text().toStdString() + "\n"));
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

void MainWindow::chat_notification(std::string notification)
{
    ui->plainTextEdit_chat_history->setPlainText(QString::fromStdString(ui->plainTextEdit_chat_history->toPlainText().toStdString() + notification + "\n"));
}
