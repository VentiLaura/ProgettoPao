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
    T_shirt(Sizes, std::string, std::string, std::string, double, std::string, int=1);
    T_shirt& operator=(Product&);
    Sizes getSize();
    void setSizes(Sizes);
    int getChestSize();
    int getWaistSize();
    int getHipsSize();
    int getSleeveLength();  
    std::string getFranchise();
    void setFranchise(std::string);
    void accept(Visitor*);  
};
}
#endif