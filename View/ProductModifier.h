#ifndef PRODUCTMODIFIER_H
#define PRODUCTMODIFIER_H
#include "Visitor/visitor.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QObject>
#include <QWidget>
#include <vector>
#include <QScrollArea>
#include <QGridLayout>
#include "ProductWidget.h"
#include "../LogicModel/Products/IncludeAllProducts.h"
#include "../LogicModel/Products/T-shirt.h"
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QStringList>
#include <QDebug>
class ProductModifier: public Visitor {
    private:
    product::Product* ModifiedObject;
    public:
    ProductModifier(product::Product*);
    void visitVideogame(product::Videogame*);
    void visitConsole(product::Console*);
    void visitTshirt(product::T_shirt*);
    void visitCollectible(product::Collectible*);
    void visitAccessory(product::Accessory*);
};
#endif