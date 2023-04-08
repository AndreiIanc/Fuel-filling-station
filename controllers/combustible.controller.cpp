#include "combustible.controller.h"

#include <QtSql>
#include "models/combustible.model.h"

CombustibleBLL::CombustibleBLL()
{

}

qreal CombustibleBLL::getCombustiblePrice(const Combustible combustible)
{
    try{
        QSqlQuery query;
        QString name = combustible.getName();
        query.prepare("SELECT price FROM combustible WHERE name = :name");
        query.bindValue(":name", name);

        if (!query.exec()) {
            qCritical("Failed to execute query");
            return 0.0;
        }

        if (query.size() == 0){
            QString warn = "Combustible " + name + "is not in the database";
            qWarning() << warn;
            return 0.0;
        }

        while (query.next()) {
            return query.value("price").toReal();
        }

        return 0.0;

    } catch(const std::exception& ex) {
        qDebug() << "Fail getCombustiblePrice" << ex.what();
        return 0.0;
    }
}

void CombustibleBLL::setCombustiblePrice(const Combustible combustible, const qreal newPrice)
{
    try{
        QSqlQuery query;
        QString name = combustible.getName();
        query.prepare("UPDATE combustible SET price = :price WHERE name = :name");
        query.bindValue(":price", newPrice);
        query.bindValue(":name", name);

        if (!query.exec()) {
            qCritical("Failed to execute query");
        }

    } catch(const std::exception& ex) {
        qDebug() << "Fail setCombustiblePrice" << ex.what();
    }
}
