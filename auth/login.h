#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

signals:
    void loginAttempted(QString username, QString password);

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
