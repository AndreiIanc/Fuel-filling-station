#include "user.h"

User::User()
{

}

bool User::getIsAdmin() const
{
    return isAdmin;
}

void User::setIsAdmin(bool newIsAdmin)
{
    isAdmin = newIsAdmin;
}

QString User::getLastName() const
{
    return lastName;
}

void User::setLastName(const QString &newLastName)
{
    lastName = newLastName;
}

QString User::getFirstName() const
{
    return firstName;
}

void User::setFirstName(const QString &newFirstName)
{
    firstName = newFirstName;
}
