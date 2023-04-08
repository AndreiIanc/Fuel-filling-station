#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

namespace Ui { class MainWindow; }

class Login;
class DatabaseManager;

class Combustible;
class CombustibleBLL;

class Tank;
class TankBLL;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    DatabaseManager *m_databaseManager = nullptr;
    Login *m_login = nullptr;

    Combustible *m_combustible = nullptr;
    CombustibleBLL *m_combustibleBLL = nullptr;
    Tank *m_tank = nullptr;
    QList<Tank> m_tankList;
    TankBLL *m_tankBLL = nullptr;

    void populateTanksUI(const QList<Tank> &tankList);

private slots:
    void destroyMainWindow();
    void onLoginAttempted(QString username, QString password);
    void onLoginResult(bool success);
    void on_checkBox_enable_price_stateChanged(int arg1);
    void on_pushButton_save_price_clicked();

};
#endif // MAINWINDOW_H
