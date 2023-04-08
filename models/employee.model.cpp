#include "employee.model.h"

int Employee::getId() const
{
    return id;
}

void Employee::setId(int newId)
{
    id = newId;
}

QString Employee::getUsername() const
{
    return username;
}

void Employee::setUsername(const QString &newUsername)
{
    username = newUsername;
}

QString Employee::getPassword() const
{
    return password;
}

void Employee::setPassword(const QString &newPassword)
{
    password = newPassword;
}

QString Employee::getFirstName() const
{
    return firstName;
}

void Employee::setFirstName(const QString &newFirstName)
{
    firstName = newFirstName;
}

QString Employee::getLastName() const
{
    return lastName;
}

void Employee::setLastName(const QString &newLastName)
{
    lastName = newLastName;
}

QString Employee::getPhoneNumber() const
{
    return phoneNumber;
}

void Employee::setPhoneNumber(const QString &newPhoneNumber)
{
    phoneNumber = newPhoneNumber;
}

QString Employee::getEmail() const
{
    return email;
}

void Employee::setEmail(const QString &newEmail)
{
    email = newEmail;
}

QDate Employee::getBirthDate() const
{
    return birthDate;
}

void Employee::setBirthDate(const QDate &newBirthDate)
{
    birthDate = newBirthDate;
}

QDateTime Employee::getCreated_at() const
{
    return created_at;
}

void Employee::setCreated_at(const QDateTime &newCreated_at)
{
    created_at = newCreated_at;
}

bool Employee::getAdmin() const
{
    return admin;
}

void Employee::setAdmin(bool newAdmin)
{
    admin = newAdmin;
}

Employee::Employee()
{

}
