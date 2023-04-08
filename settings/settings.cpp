#include "settings.h"

#include <QSettings>
#include <QFile>
#include <QMessageBox>

Settings::Settings()
{

}

DBConnectionInfo Settings::readDBConfigFile()
{
    QSettings settings(QString(":/cfg/config/config.ini"), QSettings::IniFormat);
    QString hostname = settings.value("DB/HOSTNAME", "127.0.0.1").toString();
    int port = settings.value("DB/PORT", 5432).toInt();
    QString database = settings.value("DB/DATABASE", "Fuel-filling-station").toString();
    QString username = settings.value("DB/USERNAME", "postgres").toString();
    QString password = settings.value("DB/PASSWORD", "yourPostgresPassword").toString();

    /*
     *  the real password is read from a separate file (privacy)
     *  comment this section and fill in your password in the configuration file (same for username if is different)
     */

    QFile f("E:/Qt_Projects/Fuel-filling-station/config/pass.txt");
    if (!f.open(QFile::ReadOnly | QFile::Text)){
        qCritical("The file containing the fb password cannot be opened");
        QMessageBox::critical(NULL, "Fatal error", "The file containing the fb password cannot be opened");
    }
    QTextStream in(&f);
    password = in.readAll();

    ///////////////////

    DBConnectionInfo dbConnInfo;
    dbConnInfo.hostname = hostname;
    dbConnInfo.port = port;
    dbConnInfo.database = database;
    dbConnInfo.username = username;
    dbConnInfo.password = password;

    return dbConnInfo;
}
