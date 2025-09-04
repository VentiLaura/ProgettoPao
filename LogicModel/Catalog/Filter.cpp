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

/*FilterCompatibility::FilterCompatibility(std::vector<Console_type> compatibilitycheck): CheckCompatibility(compatibilitycheck) {}
bool FilterCompatibility::Select(Product* product) const {
    if(dynamic_cast<Console*>(product)) return false;
    Videogame* videogame=dynamic_cast<Videogame*>(product);
    Accessory* accessory=dynamic_cast<Accessory*>(product);
    if (videogame) {
        for(std::vector<Console_type>::const_iterator it=CheckCompatibility.begin(); it!=CheckCompatibility.end(); it++) {
            if(!videogame->IsCompatible(*it)) return false;
        }
        return true;
    }
    if (accessory) {
        for(std::vector<Console_type>::const_iterator it=CheckCompatibility.begin(); it!=CheckCompatibility.end(); it++) {
            if(!accessory->IsCompatible(*it)) return false;
        }
        return true;
    }
}

FilterCombiner::FilterCombiner(std::vector<Filter*> combiner): Combiner(combiner) {}
bool FilterCombiner::Select(Product* product) const {
    for(std::vector<Filter*>::const_iterator it=Combiner.begin(); it!=Combiner.end(); it++) {
            if(!(*it)->Select(product)) return false;
        }
        return true;
}
        */
}