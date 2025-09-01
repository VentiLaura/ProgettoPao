#ifndef T_SHIRT
#define T_SHIRT
#include "Product.h"
#include "Enums.h"
namespace product{
class T_shirt: public Product {
    private:
    Sizes Size;
    std::string Franchise;
    public:
    ~T_shirt();
    T_shirt(Sizes, std::string, double, std::string, int=1);
    Sizes getChestSize();
    
}
}