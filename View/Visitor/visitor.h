#ifndef VISITOR_H
#define VISITOR_H
namespace product {
class Videogame;
class Console;
class Accessory;
//#include "../../LogicModel/Products/IncludeAllProducts.h"
class Collectible;
class T_shirt;
}

class Visitor {
    public:
        virtual void visitVideogame(product::Videogame* game) = 0;
        virtual void visitConsole(product::Console* console) = 0;
        virtual void visitAccessory(product::Accessory* accessory) = 0;
       virtual void visitCollectible(product::Collectible* collectible) = 0;
       virtual void visitTshirt(product::T_shirt* shirt) = 0;
};
// bisogna ridefinire i metodi visitItem
#endif