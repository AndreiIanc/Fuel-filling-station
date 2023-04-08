#include "customer.model.h"

int Customer::getId() const
{
    return id;
}

void Customer::setId(int newId)
{
    id = newId;
}

QString Customer::getFirstName() const
{
    return firstName;
}

void Customer::setFirstName(const QString &newFirstName)
{
    firstName = newFirstName;
}

QString Customer::getLastName() const
{
    return lastName;
}

void Customer::setLastName(const QString &newLastName)
{
    lastName = newLastName;
}

QString Customer::getPhoneNumber() const
{
    return phoneNumber;
}

void Customer::setPhoneNumber(const QString &newPhoneNumber)
{
    phoneNumber = newPhoneNumber;
}

QDate Customer::getBirthDate() const
{
    return birthDate;
}

void Customer::setBirthDate(const QDate &newBirthDate)
{
    birthDate = newBirthDate;
}

QDateTime Customer::getCreated_at() const
{
    return created_at;
}

void Customer::setCreated_at(const QDateTime &newCreated_at)
{
    created_at = newCreated_at;
}

qreal Customer::getCombustible() const
{
    return combustible;
}

void Customer::setCombustible(qreal newCombustible)
{
    combustible = newCombustible;
}

qreal Customer::getMediumPrice() const
{
    return mediumPrice;
}

void Customer::setMediumPrice(qreal newMediumPrice)
{
    mediumPrice = newMediumPrice;
}

qreal Customer::getFullyPaid() const
{
    return fullyPaid;
}

void Customer::setFullyPaid(qreal newFullyPaid)
{
    fullyPaid = newFullyPaid;
}

Customer::Customer()
{

}
