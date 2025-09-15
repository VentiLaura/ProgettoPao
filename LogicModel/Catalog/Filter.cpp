#include "Filter.h"
namespace filter{
       
bool FilterVideogames::Select(Product* product) const {
    Videogame* videogame=dynamic_cast<Videogame*>(product);
    if(videogame) return true;
    return false;
}

bool FilterConsoles::Select(Product* product) const {
    Console* console=dynamic_cast<Console*>(product);
    if(console) return true;
    return false;
}

bool FilterAccessories::Select(Product* product) const {
    Accessory* accessory=dynamic_cast<Accessory*>(product);
    if(accessory) return true;
    return false;
}

bool FilterCollectibles::Select(Product* product) const {
    Collectible* collectible=dynamic_cast<Collectible*>(product);
    if(collectible) return true;
    return false;
}

bool FilterTshirts::Select(Product* product) const {
    T_shirt* tshirt=dynamic_cast<T_shirt*>(product);
    if(tshirt) return true;
    return false;
}
}