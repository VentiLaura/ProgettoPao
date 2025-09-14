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
    Collectible& Collectible::operator=(Product& c) {
        Collectible* coll=dynamic_cast<Collectible*>(&c);
        if(!coll) std::__throw_invalid_argument ("Assigned Product is not a collectible");
        setName(coll->getName());
        setPrice(coll->getPrice());
        setIdProduct(coll->getIdProduct());
        setImage(coll->getImage());
        setAvailability(coll->getAvailability());
        Category = coll->GetCategory();
        Franchise = coll->GetFranchise();
        Producer = coll->GetProducer();
        return *this;
    }
}