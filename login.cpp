#include "login.h"
#include "ui_login.h"

#include <QMessageBox>
#include <QPixmap>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username == "test" && password == "test") {
        QMessageBox::information(this, "Login", "Username and password are correct");
        hide();
        mainWindow = new MainWindow(this);
        mainWindow->show();
    }
    else {
        QMessageBox::warning(this,"Login", "Username and password are incorrect");
    }
}

