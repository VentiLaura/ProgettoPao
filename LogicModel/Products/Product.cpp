#include "Product.h" 
namespace product {
Product::~Product() {}
Product::Product(std::string image, std::string name, double price, std::string idProduct, int availability): Name(name), Price(price), IdProduct(idProduct), Copies_available(availability) {
    std::ifstream file(image);
    if (file.good()) {
        Image=image;
    } else {
        Image="Immagini/No-image-found.jpg";
    }
}
std::string Product::getImage() {
    return Image;
}
void Product::setImage(std::string s) {
    std::ifstream file(s);
    if (file.good()) {
        Image=s;
    } else {
        Image="Immagini/No-image-found.jpg";
    }
    Image=s;
}
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