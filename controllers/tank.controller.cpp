#include "tank.controller.h"

#include <QtSql>
#include "models/tank.model.h"

TankBLL::TankBLL()
{

}

void TankBLL::printTanks(const QList<Tank> &tanks)
{
    qDebug() << "Tanks:";
    for (const auto& tank : tanks) {
        qDebug() << "\tid:" << tank.id << "number:" << tank.number << "capacity:" << tank.capacity
                 << "currentLevel:" << tank.currentLevel << "lastFill:" << tank.lastFill.toString();
    }
}

QList<Tank> TankBLL::getTanks()
{
    QList<Tank> tankList;
    try{
        QSqlQuery query;
        query.prepare("SELECT * FROM tank");

        if (!query.exec()) {
            qCritical("Failed to execute query");
            return tankList;
        }

        if (query.size() == 0){
            QString warn = "Empty table tank in the database";
            qWarning() << warn;
            return tankList;
        }

        Tank tank;

        while (query.next()) {
            tank.setId(query.value("id").toInt());
            tank.setNumber(query.value("number").toInt());
            tank.setCapacity(query.value("capacity").toReal());
            tank.setCurrentLevel(query.value("currentLevel").toReal());
            tank.setLastFill(query.value("lastFill").toDateTime());

            tankList.append(tank);
        }

        return tankList;

    } catch(const std::exception& ex) {
        qDebug() << "Fail getTanks" << ex.what();
        return tankList;
    }
}
