#include "Collectible.h"
namespace product {
Collectible::~Collectible() {}
Collectible::Collectible(std::string category, std::string franchise, std::string producer, std::string i, std::string name, double price, std::string id, int avaiability): Product(i, name, price, id, avaiability), Category(category), Franchise(franchise), Producer(producer) {}
std::string Collectible::GetCategory() {
    return Category;
}
void Collectible::setCategory(std::string category) {
    Category=category;
}
    std::string Collectible::GetFranchise() {
        return Franchise;
    }
    void Collectible::setFranchise(std::string franchise) {
        Franchise=franchise;
    }
    std::string Collectible::GetProducer() {
        return Producer;
    }
    void Collectible::setProducer(std::string producer) {
        Producer=producer;
    }
    void Collectible::accept(Visitor* v) {
        v->visitCollectible(this);
    }
    Collectible& Collectible::operator=(Collectible& c) {
        setName(c.getName());
        setPrice(c.getPrice());
        setIdProduct(c.getIdProduct());
        setImage(c.getImage());
        setAvailability(c.getAvailability());
        Category = c.GetCategory();
        Franchise = c.GetFranchise();
        Producer = c.GetProducer();
        return *this;
    }
}