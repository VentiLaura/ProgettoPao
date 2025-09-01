#ifndef MEMORY_H
#define MEMORY_H
#include "../Products/IncludeAllProducts.h"
#include <vector>
namespace memory {
class Memory {
    private:
    std::vector<product::Product*> Catalog;
    public:
    Memory();
    Memory(std::vector<product::Product*>);
    bool IsUnique(const std::string&) const;
    const std::vector<product::Product*>& getCatalog() const;
    Memory& Add(product::Product*);
    Memory& Add(std::vector<product::Product*>);
    Memory& Remove(std::string); 
};
}
#endif
