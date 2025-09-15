#include "Accessory.h"
namespace product {
Accessory::Accessory(double h, double l, double d, double w, std::vector<Console_type> c,std::string i, std::string n, double p, std::string id, int a): Product(i,n,p,id,a), Height(h),Lenght(l),Depth(d), Weight(w), Compatibility(c) {}
Accessory::~Accessory() {}
double Accessory::getHeight() const {
    return Height;
}
void Accessory::setHeight(double h) {
    Height=h;
}
double Accessory::getDepth() const {
    return Depth;
}
void Accessory::setDepth(double d) {
    Depth=d;
}
double Accessory::getLenght() const {
    return Lenght;
}
void Accessory::setLenght(double l) {
    Lenght=l;
}
double Accessory::getWeight() const {
    return Weight;
}
void Accessory::setWeight(double w) {
    Weight=w;
}
bool Accessory::IsCompatible(Console_type console) const {
    for(std::vector<Console_type>::const_iterator it=Compatibility.begin(); it!=Compatibility.end(); it++) {
        if(*it==console) return true;
    }
    return false;
}
const std::vector<Console_type> Accessory::getCompatibility() const {
    return Compatibility;
}
void Accessory::setCompatibility(std::vector<Console_type>& c) {
    Compatibility=c;
}
void Accessory::accept(Visitor* v) {
    v->visitAccessory(this);
}
 Accessory& Accessory::operator=(Product& a) {
    Accessory* acc=dynamic_cast<Accessory*>(&a);
    if(!acc) std::__throw_invalid_argument ("Assigned Product is not an accessory");
        setName(acc->getName());
        setPrice(acc->getPrice());
        setIdProduct(acc->getIdProduct());
        setImage(acc->getImage());
        setAvailability(acc->getAvailability());
        Compatibility=acc->getCompatibility();
        Height = acc->getHeight();
        Depth = acc->getDepth();
        Lenght = acc->getLenght();
        Weight=acc->getWeight();
        return *this;
    }
}