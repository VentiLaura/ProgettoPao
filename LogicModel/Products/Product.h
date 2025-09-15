#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <fstream>
#include "../../View/Visitor/visitor.h"
namespace product {
class Product {
    private:
    std::string Image;
    std::string Name;
    double Price;
    std::string IdProduct;
    int Copies_available;
    public:
    Product(std::string, std::string, double, std::string, int=1);
    virtual ~Product() = 0;
    virtual Product& operator=(Product&) =0;
    std::string getImage();
    void setImage(std::string);
    std::string getName() const; 
    void setName(std::string);
    int getAvailability() const;
    void setAvailability(int);
    std::string getIdProduct() const;
    void setIdProduct(std::string);
    double getPrice() const;
    void setPrice(double);
    virtual void accept(Visitor*)=0;
};
}
#endif