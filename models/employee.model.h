#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QDateTime>
#include <QString>

// Employee Table
class Employee {
public:
    int id;
    QString username;
    QString password;
    QString firstName;
    QString lastName;
    QString phoneNumber;
    QString email;
    QDate birthDate;
    QDateTime created_at;
    bool admin;

    Employee();
    int getId() const;
    void setId(int newId);
    QString getUsername() const;
    void setUsername(const QString &newUsername);
    QString getPassword() const;
    void setPassword(const QString &newPassword);
    QString getFirstName() const;
    void setFirstName(const QString &newFirstName);
    QString getLastName() const;
    void setLastName(const QString &newLastName);
    QString getPhoneNumber() const;
    void setPhoneNumber(const QString &newPhoneNumber);
    QString getEmail() const;
    void setEmail(const QString &newEmail);
    QDate getBirthDate() const;
    void setBirthDate(const QDate &newBirthDate);
    QDateTime getCreated_at() const;
    void setCreated_at(const QDateTime &newCreated_at);
    bool getAdmin() const;
    void setAdmin(bool newAdmin);
};

#endif // EMPLOYEE_H
