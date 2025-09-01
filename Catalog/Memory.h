#ifndef MEMORY_H
#define MEMORY_H
#include "../Products/IncludeAllProducts.h"
#include <vector>
namespace memory {
class Memory {
    private:
    std::vector<product::Product*> Catalog;
    public:
    const std::vector<product::Product*>& getCatalog() const;
    Memory& Add(product::Product*);
    Memory& Remove(unsigned int); 
};
}
#endif
