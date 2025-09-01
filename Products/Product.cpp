#ifndef PRODUCT_CPP
#define PRODUCT_CPP
#include "Product.h"
namespace product {
Product::~Product() {}
Product::Product(double price, unsigned int idProduct, int availability): Price(price), IdProduct(idProduct), Copies_available(availability) {}
int Product::getAvailability() const {
    return Copies_available;
}
void Product::setAvailability(int disp) {
    Copies_available=disp;
}
int Product::getIdProduct() const {
    return IdProduct;
}
void Product::setIdProduct(int ID) {
    IdProduct=ID;
}
double Product::getPrice() const {
    return Price;
}
void Product::setPrice(double price) {
    Price=price;
}
}
#endif