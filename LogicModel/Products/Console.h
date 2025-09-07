#ifndef CONSOLE_H
#define CONSOLE_H
#include "IncludeAllProducts.h"
namespace product {
class Console: public Product {
    private:
    Console_type Serie;
    std::string Memory;
    public:
    ~Console();
    Console(Console_type, std::string, std::string, double, std::string, int=1);
    Console_type getSerie() const;
    void setSerie(Console_type&);
    std::string getMemory();
    void setMemory(std::string);
};
}
#endif