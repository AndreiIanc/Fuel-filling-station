#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QRegularExpression>

#include "auth/login.h"
#include "dbconnection/databasemanager.h"

#include "models/combustible.model.h"
#include "models/tank.model.h"

#include "controllers/combustible.controller.h"
#include "controllers/tank.controller.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_databaseManager(new DatabaseManager)
    , m_login(new Login)
    , m_combustible(new Combustible)
    , m_combustibleBLL(new CombustibleBLL)
    , m_tank(new Tank)
    , m_tankBLL(new TankBLL)
{
    ui->setupUi(this);

    // on login destroyed, destroy mainwindow too
    connect(m_login, &QDialog::finished, this, &MainWindow::destroyMainWindow);

    if (!m_databaseManager->createConnection()) {
        // Connection failed, close the application
        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"), tr("Unable to establish a database connection.\n"));
        destroyMainWindow();
    }

    // Connect signals and slots
    connect(m_login, &Login::loginAttempted, this, &MainWindow::onLoginAttempted);
    connect(m_databaseManager, &DatabaseManager::loginResult, this, &MainWindow::onLoginResult);

    // Hide main window until login is successful
    this->hide();
    m_login->exec();
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
    if (!success) {
        QMessageBox::warning(this, "Login Error", "Invalid username or password");
    }
    else {
        qInfo("Login successful");

        // show user in the status bar
        ui->statusbar->showMessage(m_databaseManager->getUser().getFirstName() + " " + m_databaseManager->getUser().getLastName());

        // admin only
        if (m_databaseManager->getUser().getIsAdmin()) {
            ui->tab_Employees->show();
            ui->groupBox_refill_tank->show();
            ui->checkBox_enable_price->show();
            ui->pushButton_save_price->show();
        } else {
            ui->tab_Employees->hide();
            ui->groupBox_refill_tank->hide();
            ui->checkBox_enable_price->hide();
            ui->pushButton_save_price->hide();
        }

        // get db data and fill UI

        // combustible
        m_combustible->setName("diesel");
        ui->lineEdit_price->setText(QString::number(m_combustibleBLL->getCombustiblePrice(*m_combustible),'f', 2));

        // tanks
        m_tankList = m_tankBLL->getTanks();
        m_tankBLL->printTanks(m_tankList);
        populateTanksUI(m_tankList);

        this->show();
        m_login->hide();
    }
}

void MainWindow::on_checkBox_enable_price_stateChanged(int checkState)
{
    bool isChecked = (checkState == Qt::Checked);
    if (isChecked) {
        ui->lineEdit_price->setReadOnly(false);
    } else {
        ui->lineEdit_price->setReadOnly(true);
    }
}

void MainWindow::on_pushButton_save_price_clicked()
{
    static QRegularExpression regex("^\\d+(\\.\\d{1,2})?$");

    QRegularExpressionMatch match = regex.match(ui->lineEdit_price->text());
    if (match.hasMatch()) {
        m_combustibleBLL->setCombustiblePrice(*m_combustible, ui->lineEdit_price->text().toDouble());
        ui->checkBox_enable_price->setChecked(false);
        ui->lineEdit_price->setReadOnly(true);
        QMessageBox::information(this,"Info","New price saved");
    } else {
        ui->lineEdit_price->setText(QString::number(m_combustibleBLL->getCombustiblePrice(*m_combustible),'f', 2));
        QMessageBox::warning(this,"Warning","Invalid value for price");
    }
}

void MainWindow::populateTanksUI(const QList<Tank> &tankList)
{
    // set the number of rows and columns in the table
    ui->tableWidget_tanks->setRowCount(tankList.size());
    ui->tableWidget_tanks->setColumnCount(5);

    // set the headers for each column
    ui->tableWidget_tanks->setHorizontalHeaderLabels(QStringList() << "Number" << "Amount"<< "Capacity" << "Last Fill" << "% remaining");

    // set the vertical header labels to be numbers
    QVector<QString> rowLabels(tankList.size());
    for (int i = 0; i < tankList.size(); i++) {
        rowLabels[i] = QString::number(i+1);
    }
    ui->tableWidget_tanks->setVerticalHeaderLabels(rowLabels);

    // iterate over the list and add the values to the table
    for (int i = 0; i < tankList.size(); ++i) {
        Tank tank = tankList.at(i);

        qreal procent = tank.getCurrentLevel() / tank.getCapacity() * 100.0;
        QString procentStr = QString::number(procent, 'f', 2);

        QString lastFill = (tank.getLastFill().toString().isEmpty()) ? "N/A" : tank.getLastFill().toString();

        QTableWidgetItem* numberItem = new QTableWidgetItem(QString::number(tank.getNumber()));
        QTableWidgetItem* capacityItem = new QTableWidgetItem(QString::number(tank.getCapacity()));
        QTableWidgetItem* currentLevelItem = new QTableWidgetItem(QString::number(tank.getCurrentLevel()));
        QTableWidgetItem* lastFillItem = new QTableWidgetItem(lastFill);
        QTableWidgetItem* remaining = new QTableWidgetItem(procentStr);

        numberItem->setTextAlignment(Qt::AlignCenter);
        currentLevelItem->setTextAlignment(Qt::AlignCenter);
        capacityItem->setTextAlignment(Qt::AlignCenter);
        lastFillItem->setTextAlignment(Qt::AlignCenter);
        remaining->setTextAlignment(Qt::AlignCenter);

        ui->tableWidget_tanks->setItem(i, 0, numberItem);
        ui->tableWidget_tanks->setItem(i, 1, currentLevelItem);
        ui->tableWidget_tanks->setItem(i, 2, capacityItem);
        ui->tableWidget_tanks->setItem(i, 3, lastFillItem);
        ui->tableWidget_tanks->setItem(i, 4, remaining);
    }

    // Resize the table widget to match the sizes of its columns and rows
    ui->tableWidget_tanks->resizeColumnsToContents();
    ui->tableWidget_tanks->resizeRowsToContents();
}

