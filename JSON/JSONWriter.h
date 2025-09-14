#ifndef JSONWRITER_H
#define JSONWRITER_H
#include <vector>
#include <iostream>
#include "../LogicModel/Products/IncludeAllProducts.h"
#include "../LogicModel/Catalog/Memory.h"
#include <QFile> 
#include <QJsonDocument> 
#include <QJsonObject> 
#include <QJsonArray> 
#include <QDebug>
#include <stdexcept>
#include "../View/Visitor/visitor.h"

class JSONWriter : public Visitor {
private:
    QJsonArray array;
    QJsonObject currentObject;
    QString filePath;

public:
    explicit JSONWriter(const QString& filePath);

    void removeById(const std::string& id);
    void appendProduct(product::Product* p);
    void save();

    void visitAccessory(product::Accessory*) override;
    void visitVideogame(product::Videogame*) override;
    void visitConsole(product::Console*) override;
    void visitCollectible(product::Collectible*) override;
    void visitTshirt(product::T_shirt*) override;
};
#endif