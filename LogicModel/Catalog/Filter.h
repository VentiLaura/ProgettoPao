#ifndef FILTER_H
#define FILTER_H
#include "../Products/IncludeAllProducts.h"
using namespace product;
namespace filter {
class Filter {
    public:
    virtual bool Select(Product*) const=0;
    virtual ~Filter()=default;
};

class FilterVideogames: public Filter {
    public: 
    bool Select(Product*) const;
};

class FilterConsoles: public Filter {
    public: 
    bool Select(Product*) const;
};

class FilterAccessories: public Filter {
    public: 
    bool Select(Product*) const;
};

class FilterCollectibles: public Filter {
    public: 
    bool Select(Product*) const;
};

class FilterTshirts: public Filter {
    public: 
    bool Select(Product*) const;
};
}
#endif