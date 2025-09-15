#ifndef XMLWRITER_H
#define XMLWRITER_H
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QFile>
#include "../LogicModel/Products/IncludeAllProducts.h"
#include "../View/Visitor/visitor.h"
#include <QTextStream>
#include <stdexcept>
namespace xml {
class XMLWriter: public Visitor {
    private:
    QDomDocument doc;
    QDomElement root;
    QString filePath;
    void writeCommonFields(product::Product*);
    public:
    QDomElement productElement;
     XMLWriter(const QString& filePath);
    void save();  
    void removeById(const std::string& id);
    void appendProduct(product::Product* p);
    void visitAccessory(product::Accessory*) override;
    void visitVideogame(product::Videogame*) override;
    void visitConsole(product::Console*) override;
    void visitCollectible(product::Collectible*) override;
    void visitTshirt(product::T_shirt*) override;
};
}
#endif