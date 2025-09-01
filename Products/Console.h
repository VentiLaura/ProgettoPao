#ifndef CONSOLE_H
#define CONSOLE_H
#include "Products/IncludeAllProducts.h"
namespace product {
class Console: public Product {
    private:
    Console_type Serie;
    public:
    ~Console();
    Console(Console_type, double, std::string, int=1);
    Console_type getSerie() const;
    void setSerie(Console_type&);
};
}
#endif