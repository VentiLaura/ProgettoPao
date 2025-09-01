#ifndef ACCESSORY_CPP
#define ACCESSORY_CPP
#include "Accessory.h"
#include "Enums.h"
#include <vector>
namespace product {
Accessory::Accessory(double h, double l, double d, double w, std::vector<Console_type> c, double p, std::string n, unsigned int id, int a): Product(p,id,a), Height(h), Weight(w), Lenght(l), Depth(d), Compatibility(c), Name(n) {}
Accessory::~Accessory() {}
std::string Accessory::getName() const {
    return Name;
}
void Accessory::setName(std::string n) {
    Name=n;
}
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
const std::vector<Console_type>& Accessory::getCompatibility() const {
    return Compatibility;
}
void Accessory::setCompatibility(std::vector<Console_type>& c) {
    Compatibility=c;
}
}
#endif