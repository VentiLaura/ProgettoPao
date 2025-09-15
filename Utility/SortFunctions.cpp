#include "SortFunctions.h"
#include "../LogicModel/Catalog/Sorter.h"
using namespace product;
using namespace sort;
namespace sortfunctions {
std::vector<product::Product*> applySort(const QString& sortType, std::vector<product::Product*>& products) {
    if (sortType=="Nome") {
        SortByName(products);
    } else if (sortType=="Prezzo più basso") {
        SortByPriceAsc(products);
    } else if (sortType=="Prezzo più alto") {
        SortByPriceDesc(products);
    } else if (sortType=="Disponibilità") {
        SortByAvailability(products);
    }
    return products;
}
}