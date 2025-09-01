#ifndef MEMORY_CPP
#define MEMORY_CPP
#include <vector>
#include "Memory.h"
namespace memory {
const std::vector<product::Product*>& Memory::getCatalog() const {
    return Catalog;
}
Memory& Memory::Add(product::Product* product) {
    Catalog.push_back(product);
    return *this;
}
Memory& Memory::Remove(unsigned int id) {
    for(std::vector<product::Product*>::iterator it=Catalog.begin(); it!=Catalog.end(); it++) {
        if((*it)->getIdProduct()==id) {
            delete *it;
            Catalog.erase(it);
        }
    }
    return *this;
}
}
#endif