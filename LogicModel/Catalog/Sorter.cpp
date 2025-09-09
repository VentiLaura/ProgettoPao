#include "Sorter.h"
#include <algorithm>

namespace sort{
    void SortByPriceAsc(std::vector<product::Product*>& products){
        std::sort(products.begin(), products.end(),
                  [](product::Product* a, product::Product* b) {
                      return a->getPrice() < b->getPrice();
                  });
    }
    void SortByPriceDesc(std::vector<product::Product*>& products){
        std::sort(products.begin(), products.end(),
                  [](product::Product* a, product::Product* b) {
                      return a->getPrice() > b->getPrice();
                  });
    }
     void SortByName(std::vector<product::Product*>& products) {
        std::sort(products.begin(), products.end(),
            [](product::Product* a, product::Product* b) {
                return a->getName() < b->getName();
            });
    }

    void SortByAvailability(std::vector<product::Product*>& products) {
        std::sort(products.begin(), products.end(),
            [](product::Product* a, product::Product* b) {
                return a->getAvailability() > b->getAvailability();
            });
    }

}


    

