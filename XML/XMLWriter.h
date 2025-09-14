#ifndef XMLWRITER_H
#define XMLWRITER_H
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QFile>
#include "../LogicModel/Products/IncludeAllProducts.h"
#include "../View/Visitor/visitor.h"
#include <QDebug>
#include <QTextStream>

class XMLWriter: public Visitor {
private:
    QDomDocument doc;          // ora non più puntatore
    QDomElement root;
    QString filePath;
public:
    QDomElement productElement;
     XMLWriter(const QString& filePath);

    void save();  // salva il documento aggiornato su file
    void removeById(const std::string& id);
    void appendProduct(product::Product* p);

    void visitAccessory(product::Accessory*) override;
    void visitVideogame(product::Videogame*) override;
    void visitConsole(product::Console*) override;
    void visitCollectible(product::Collectible*) override;
    void visitTshirt(product::T_shirt*) override;
    //void RemoveByIdXML(const QString&, const std::string&);
private:
    void writeCommonFields(product::Product*);
};
#endif