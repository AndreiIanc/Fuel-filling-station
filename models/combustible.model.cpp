#include "combustible.model.h"

int Combustible::getId() const
{
    return id;
}

void Combustible::setId(int newId)
{
    id = newId;
}

QString Combustible::getName() const
{
    return name;
}

void Combustible::setName(const QString &newName)
{
    name = newName;
}

qreal Combustible::getPrice() const
{
    return price;
}

void Combustible::setPrice(qreal newPrice)
{
    price = newPrice;
}

Combustible::Combustible()
{

}
