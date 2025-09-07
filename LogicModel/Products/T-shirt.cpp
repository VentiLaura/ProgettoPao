#include "T-shirt.h"
namespace product {
T_shirt::~T_shirt() {}
T_shirt::T_shirt(Sizes s, std::string f, std::string i, std::string n, double p, std::string id, int av): Product(i,n,p,id,av), Size(s), Franchise(f) {}
int T_shirt::getChestSize() {
    switch(Size) {
        case Sizes::L: return 103;
        case Sizes::M: return 95;
        case Sizes::S: return 89;
        case Sizes::XL: return 110;
        case Sizes::XS: return 83;
    }
}
int T_shirt::getWaistSize() {
    switch(Size) {
        case Sizes::L: return 89;
        case Sizes::M: return 81;
        case Sizes::S: return 74;
        case Sizes::XL: return 95;
        case Sizes::XS: return 67;
    }

}
int T_shirt::getHipsSize() {
    switch(Size) {
        case Sizes::L: return 106;
        case Sizes::M: return 100;
        case Sizes::S: return 93;
        case Sizes::XL: return 112;
        case Sizes::XS: return 90;
    }
}
int T_shirt::getSleeveLength() {
    switch(Size) {
        case Sizes::L: return 66;
        case Sizes::M: return 64;
        case Sizes::S: return 62;
        case Sizes::XL: return 68;
        case Sizes::XS: return 60;
    }
}
std::string T_shirt::getFranchise() {
    return Franchise;
}
void T_shirt::setFranchise(std::string f) {
    Franchise=f;
}
Sizes T_shirt::getSize() {
    return Size;
}
void T_shirt::setSizes(Sizes s) {
    Size=s;
}
}