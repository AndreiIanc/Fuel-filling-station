#ifndef TANKBLL_H
#define TANKBLL_H

#include <QList>

class Tank;

class TankBLL
{
public:
    TankBLL();

    Tank *m_tank = nullptr;
    QList<Tank> m_tankList;

    void printTanks(const QList<Tank>& tanks);

    QList<Tank> getTanks();
};

#endif // TANKBLL_H
