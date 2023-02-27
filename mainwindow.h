#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "setting.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_go_to_settings_clicked();

    void on_pushButton_send_messege_clicked();

    void on_pushButton_set_username_clicked();

    void write_text_to_chat_history_like_a_server_sending();

public:
    std::string messege_to_send();
    void send_messege_like_a_server();
    Q_INVOKABLE void write_text_to_chat_history_reciving(std::string messege);
    void set_settings_server();
    void recive_messege_like_a_server();
    void start_server_settings();


private:
    Ui::MainWindow *ui;
    setting* settingWindow;

};


extern std::string username;

#endif // MAINWINDOW_H
