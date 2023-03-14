#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "qobject.h"
#include "settings.h"
#include "user.h"

#include <QString>
#include <QtSql>

class DatabaseManager : public QObject
{
    Q_OBJECT

public:
    explicit DatabaseManager();
    ~DatabaseManager();

    Settings *m_settings = nullptr;
    User m_user;

    QSqlDatabase db;

    bool createConnection();
    User getUser();

signals:
    void loginResult(bool success);

public slots:
    void attemptLogin(QString username, QString password);
};

#endif // DATABASEMANAGER_H
