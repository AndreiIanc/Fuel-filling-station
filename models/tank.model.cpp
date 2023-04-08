#include "tank.model.h"

Tank::Tank()
{

}

int Tank::getId() const
{
    return id;
}

void Tank::setId(int newId)
{
    id = newId;
}

int Tank::getNumber() const
{
    return number;
}

void Tank::setNumber(int newNumber)
{
    number = newNumber;
}

qreal Tank::getCapacity() const
{
    return capacity;
}

void Tank::setCapacity(qreal newCapacity)
{
    capacity = newCapacity;
}

qreal Tank::getCurrentLevel() const
{
    return currentLevel;
}

void Tank::setCurrentLevel(qreal newCurrentLevel)
{
    currentLevel = newCurrentLevel;
}

QDateTime Tank::getLastFill() const
{
    return lastFill;
}

void Tank::setLastFill(const QDateTime &newLastFill)
{
    lastFill = newLastFill;
}

void Tank::printTank() const
{
    qDebug() << "id:" << id << "number:" << number << "capacity:" << capacity
             << "currentLevel:" << currentLevel << "lastFill:" << lastFill.toString();
}
