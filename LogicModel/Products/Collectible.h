#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H
#include "Product.h"
namespace product {
class Collectible: public Product {
    private:
    std::string Category;
    std::string Franchise;
    std::string Producer;
    public:
    ~Collectible();
    Collectible(std::string, std::string, std::string, std::string, std::string, double, std::string, int=1);
    Collectible& operator=(Product&);
    std::string GetCategory();
    void setCategory(std::string);
    std::string GetFranchise();
    void setFranchise(std::string);
    std::string GetProducer();
    void setProducer(std::string);
    void accept(Visitor*);
};
}
#endif