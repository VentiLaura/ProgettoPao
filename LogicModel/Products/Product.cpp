#include "Product.h"
namespace product {
Product::~Product() {}
Product::Product(std::string image, std::string name, double price, std::string idProduct, int availability): Image(image), Name(name), Price(price), IdProduct(idProduct), Copies_available(availability) {}
std::string Product::getName() const {
    return Name;
}
void Product::setName(std::string n) {
    Name=n;
}
int Product::getAvailability() const {
    return Copies_available;
}
void Product::setAvailability(int disp) {
    Copies_available=disp;
}
std::string Product::getIdProduct() const {
    return IdProduct;
}
void Product::setIdProduct(std::string ID) {
    IdProduct=ID;
}
double Product::getPrice() const {
    return Price;
}
void Product::setPrice(double price) {
    Price=price;
}
}