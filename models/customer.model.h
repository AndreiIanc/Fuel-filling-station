#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QDateTime>
#include <QString>

// Customer Table
class Customer {
public:
    int id;
    QString firstName;
    QString lastName;
    QString phoneNumber;
    QDate birthDate;
    QDateTime created_at;
    qreal combustible;
    qreal mediumPrice;
    qreal fullyPaid;

    Customer();

    int getId() const;
    void setId(int newId);
    QString getFirstName() const;
    void setFirstName(const QString &newFirstName);
    QString getLastName() const;
    void setLastName(const QString &newLastName);
    QString getPhoneNumber() const;
    void setPhoneNumber(const QString &newPhoneNumber);
    QDate getBirthDate() const;
    void setBirthDate(const QDate &newBirthDate);
    QDateTime getCreated_at() const;
    void setCreated_at(const QDateTime &newCreated_at);
    qreal getCombustible() const;
    void setCombustible(qreal newCombustible);
    qreal getMediumPrice() const;
    void setMediumPrice(qreal newMediumPrice);
    qreal getFullyPaid() const;
    void setFullyPaid(qreal newFullyPaid);
};

#endif // CUSTOMER_H
