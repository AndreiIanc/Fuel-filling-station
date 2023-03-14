#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User();

    QString firstName;
    QString lastName;
    bool isAdmin;

    QString getFirstName() const;
    void setFirstName(const QString &newFirstName);
    QString getLastName() const;
    void setLastName(const QString &newLastName);
    bool getIsAdmin() const;
    void setIsAdmin(bool newIsAdmin);
};

#endif // USER_H
