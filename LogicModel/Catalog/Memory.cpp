#include <vector>
#include "Memory.h"
#include <string>
#include <stdexcept>
namespace memory {
Memory::Memory() {}
Memory::Memory(std::vector<product::Product*> c): Catalog(c) {}
const std::vector<product::Product*>& Memory::getCatalog() const {
    return Catalog;
}
bool Memory::IsUnique(const std::string& id) const {
    for(std::vector<product::Product*>::const_iterator it=Catalog.begin(); it!=Catalog.end(); it++) {
        if((*it)->getIdProduct()==id) return false;
    }
    return true;
}
Memory& Memory::Add(product::Product* product) {
    if(IsUnique(product->getIdProduct())) { 
        Catalog.push_back(product);
        return *this;
    } else {
        throw std::invalid_argument("Elemento non inserito perché id equivalente: " + product->getIdProduct());
    }
}
Memory& Memory::Add(std::vector<product::Product*> products) {
    std::string errors;
    for(std::vector<product::Product*>::iterator it=products.begin(); it!=products.end(); it++) {
        if(IsUnique((*it)->getIdProduct())) {
            Catalog.push_back(*it);
        } else {
            errors+(*it)->getIdProduct()+"\n";
        }
    }
    if(errors.empty()) {
        return *this;
    } else {
        throw std::invalid_argument("Elemento/i non inserito/i perché id equivalente/i: " + errors);
    }
}
Memory& Memory::Remove(std::string id) {
    for(std::vector<product::Product*>::iterator it=Catalog.begin(); it!=Catalog.end(); it++) {
        if((*it)->getIdProduct()==id) {
            delete *it;
            Catalog.erase(it);
        }
    }
    return *this;
}
}