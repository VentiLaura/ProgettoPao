#ifndef SORTER_H
#define SORTER_H
#include "../../LogicModel/Products/Product.h"
#include <vector>
#include <algorithm>

namespace sort {
void SortByPriceAsc(std::vector<product::Product*>& products);
void SortByPriceDesc(std::vector<product::Product*>& products);
void SortByName(std::vector<product::Product*>& products);
void SortByAvailability(std::vector<product::Product*>& products);
}
#endif