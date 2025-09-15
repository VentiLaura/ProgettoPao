#ifndef FILTERFUNCTIONS_H
#define FILTERFUNCTIONS_H

#include <QString>
#include <vector>
#include "../LogicModel/Products/Product.h"

namespace filterfunctions {
    std::vector<product::Product*> applyFilter(const QString&,const std::vector<product::Product*>&);
}

#endif