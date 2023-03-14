#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "databasemanager.h"

namespace Ui { class MainWindow; }

class Login;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Login *m_login = nullptr;
    DatabaseManager *m_databaseManager = nullptr;

private slots:
    void destroyMainWindow();
    void onLoginAttempted(QString username, QString password);
    void onLoginResult(bool success);

};
#endif // MAINWINDOW_H
