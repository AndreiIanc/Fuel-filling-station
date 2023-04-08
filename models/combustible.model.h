#ifndef COMBUSTIBLE_H
#define COMBUSTIBLE_H

#include <QString>

// Combustible Table
class Combustible {
public:
    int id;
    QString name;
    qreal price;

    Combustible();

    int getId() const;
    void setId(int newId);
    QString getName() const;
    void setName(const QString &newName);
    qreal getPrice() const;
    void setPrice(qreal newPrice);
};

#endif // COMBUSTIBLE_H
