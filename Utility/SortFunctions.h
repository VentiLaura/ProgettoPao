#ifndef SORTFUNCTIONS_H
#define SORTFUNCTIONS_H

#include <QString>
#include <vector>
#include "../LogicModel/Products/Product.h"

namespace sortfunctions {
    std::vector<product::Product*> applySort(const QString&, std::vector<product::Product*>&);
}
#endif