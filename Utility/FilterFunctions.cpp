#include "FilterFunctions.h"
#include "../LogicModel/Catalog/Filter.h"  // le classi FilterConsoles, etc.

using namespace product;

namespace filterfunctions {

std::vector<Product*> applyFilter(const QString& selectedFilter,
        const std::vector<Product*>& allProducts) {
    std::vector<Product*> filtered;

    if (selectedFilter == "Tutti") {
        return allProducts;
    }

    const filter::Filter* chosenFilter = nullptr;

    if (selectedFilter == "Console")
        chosenFilter = new filter::FilterConsoles;
    else if (selectedFilter == "Videogiochi")
        chosenFilter = new filter::FilterVideogames;
    else if (selectedFilter == "Accessori")
        chosenFilter = new filter::FilterAccessories;
    else if (selectedFilter == "Collezionabili")
        chosenFilter = new filter::FilterCollectibles;
    else if (selectedFilter == "Magliette")
        chosenFilter = new filter::FilterTshirts;

    if (chosenFilter) {
        for (auto it = allProducts.begin(); it != allProducts.end(); ++it) {
            auto prod = *it;
            if (chosenFilter->Select(prod)) {
                filtered.push_back(prod);
            }
        }
        delete chosenFilter;
    }

    return filtered;
}

}