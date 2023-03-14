#include "databasemanager.h"

#include <QMessageBox>

DatabaseManager::DatabaseManager()
{
    m_settings = new Settings();

    db = QSqlDatabase::addDatabase("QPSQL");
}

DatabaseManager::~DatabaseManager()
{
    db.close(); // close the database connection when done
}

bool DatabaseManager::createConnection()
{
    DBConnectionInfo dbConnInfo = m_settings->readDBConfigFile();

    db.setHostName(dbConnInfo.hostname);
    db.setPort(dbConnInfo.port);
    db.setDatabaseName(dbConnInfo.database);
    db.setUserName(dbConnInfo.username);
    db.setPassword(dbConnInfo.password);

    if (!db.open()) {
        return false;
    }

    qInfo("Database opened successfully");
    return true;
}

User DatabaseManager::getUser()
{
    return m_user;
}

void DatabaseManager::attemptLogin(QString username, QString password)
{
    // check the credentials against the database

    bool success = false;  // assume fail for now

    QSqlQuery query;
    query.prepare("SELECT * FROM employee WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qCritical("Failed to execute query");
        QMessageBox::critical(nullptr, tr("Login"), tr("Cannot execute query"));
        return;
    }

    QString firstName = "";
    QString lastName = "";
    bool admin = false;

    while (query.next()) {
        firstName = query.value("firstName").toString();
        lastName = query.value("lastName").toString();
        admin = query.value("lastName").toBool();

        m_user.setFirstName(firstName);
        m_user.setLastName(lastName);
        m_user.setIsAdmin(admin);

        success = true;

        break;
    }

    if (firstName == ""){
        qWarning("The user with these credentials is not in the database");
    }

    emit loginResult(success);
}
