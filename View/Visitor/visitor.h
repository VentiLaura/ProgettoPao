#ifndef VISITOR_H
#define VISITOR_H

class Videogame;
class Console;
class Accessory;
// class Collectible;
// class Tshirt

class Visitor {
    public:
        virtual void visitVideogame(Videogame* game) = 0;
        virtual void visitConsole(Console* console) = 0;
        virtual void visitAccessory(Accessory* accessory) = 0;
//       virtual void visitCollectible(Collectible* collectible) = 0;
//       virtual void visitTshirt(Tshirt* shirt) = 0;
};
// bisogna ridefinire i metodi visitItem
#endif