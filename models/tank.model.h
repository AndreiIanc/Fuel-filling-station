#ifndef TANK_H
#define TANK_H

#include <QDateTime>
#include <QString>

// Tank Table
class Tank {
public:
    int id;
    int number;
    qreal capacity;
    qreal currentLevel;
    QDateTime lastFill;

    Tank();

    int getId() const;
    void setId(int newId);
    int getNumber() const;
    void setNumber(int newNumber);
    qreal getCapacity() const;
    void setCapacity(qreal newCapacity);
    qreal getCurrentLevel() const;
    void setCurrentLevel(qreal newCurrentLevel);
    QDateTime getLastFill() const;
    void setLastFill(const QDateTime &newLastFill);

    void printTank() const;
};

#endif // TANK_H
