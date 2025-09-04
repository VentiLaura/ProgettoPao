#ifndef MEMORY_H
#define MEMORY_H
#include "../Products/IncludeAllProducts.h"
#include <vector>
namespace memory {
class Memory {
    private:
    std::vector<product::Product*> Catalog;
    Memory();
    Memory(std::vector<product::Product*>);     //questa potrebbe essere inutile
    Memory& operator=(Memory&)=delete;
    Memory(Memory&)=delete;
    public:
    bool IsUnique(const std::string&) const;
    static Memory& getCentralMemoryInstance();
    Memory& Add(product::Product*);
    Memory& Add(std::vector<product::Product*>);
    Memory& Remove(std::string); 
    std::vector<product::Product*> getCatalog();
};
}
#endif
