#include "ProductModifier.h"
ProductModifier::ProductModifier(product::Product* product): ModifiedObject(product) {}
void ProductModifier::visitVideogame(product::Videogame* videogame) {
    product::Videogame* mod=dynamic_cast<product::Videogame*>(ModifiedObject);
    qDebug()<<QString::fromStdString(mod->getName());
    *videogame=*mod;
}
void ProductModifier::visitConsole(product::Console* console) {
    product::Console* mod=dynamic_cast<product::Console*>(ModifiedObject);
    *console=*mod;
}
void ProductModifier::visitTshirt(product::T_shirt* t_shirt) {
    product::T_shirt* mod=dynamic_cast<product::T_shirt*>(ModifiedObject);
    *t_shirt=*mod;
}
void ProductModifier::visitCollectible(product::Collectible* collectible) {
    product::Collectible* mod=dynamic_cast<product::Collectible*>(ModifiedObject);
    *collectible=*mod;
}
void ProductModifier::visitAccessory(product::Accessory* accessory) {
    product::Accessory* mod=dynamic_cast<product::Accessory*>(ModifiedObject);
    *accessory=*mod;
}