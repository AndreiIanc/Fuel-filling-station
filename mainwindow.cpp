#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "login.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_login(new Login)
    , m_databaseManager(new DatabaseManager)
{
    ui->setupUi(this);

    // on login destroyed, destroy mainwindow too
    connect(m_login, &QDialog::finished, this, &MainWindow::destroyMainWindow);

    if (m_databaseManager->createConnection()) {

        // Connect signals and slots
        connect(m_login, &Login::loginAttempted, this, &MainWindow::onLoginAttempted);
        connect(m_databaseManager, &DatabaseManager::loginResult, this, &MainWindow::onLoginResult);

        // Hide main window until login is successful
        this->hide();
        m_login->exec();
    }
    else {
        // Connection failed, close the application
        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"), tr("Unable to establish a database connection.\n"));
        destroyMainWindow();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::destroyMainWindow()
{
    this->close();
    deleteLater();
}

void MainWindow::onLoginAttempted(QString username, QString password)
{
    m_databaseManager->attemptLogin(username, password);
}

void MainWindow::onLoginResult(bool success)
{
    if (success) {
        qInfo("Login successful");

        this->show();
        m_login->hide();
    }
    else {
        QMessageBox::warning(this, "Login Error", "Invalid username or password");
    }
}

