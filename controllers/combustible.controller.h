#ifndef COMBUSTIBLEBLL_H
#define COMBUSTIBLEBLL_H

#include "qglobal.h"
class Combustible;

class CombustibleBLL
{
public:
    CombustibleBLL();

    qreal getCombustiblePrice(const Combustible combustible);
    void setCombustiblePrice(const Combustible combustible, const qreal newPrice);
};

#endif // COMBUSTIBLEBLL_H
