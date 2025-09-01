#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
namespace product {
class Product {
    private:
    double Price;
    std::string IdProduct;
    int Copies_available;
    public:
    Product(double, std::string, int=1);
    virtual ~Product() = 0;
    int getAvailability() const;
    void setAvailability(int);
    std::string getIdProduct() const;
    void setIdProduct(std::string);
    double getPrice() const;
    void setPrice(double);
};
}
#endif