#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>

struct DBConnectionInfo {
    QString hostname;
    int port;
    QString database;
    QString username;
    QString password;
};

class Settings
{
public:
    Settings();

    DBConnectionInfo readDBConfigFile();
};

#endif // SETTINGS_H
