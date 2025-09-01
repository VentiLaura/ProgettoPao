#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
namespace product {
class Product {
    private:
    double Price;
    unsigned int IdProduct;
    int Copies_available;
    public:
    Product(double, unsigned int, int=1);
    virtual ~Product() = 0;
    int getAvailability() const;
    void setAvailability(int);
    int getIdProduct() const;
    void setIdProduct(int);
    double getPrice() const;
    void setPrice(double);
};
}
#endif