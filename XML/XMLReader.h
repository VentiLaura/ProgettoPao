#ifndef XMLREADER_H
#define XMLREADER_H
#include "../LogicModel/Products/Product.h"
#include <vector>
#include <QString>
#include <QtXml/QDomDocument>

namespace xml { 
    product::Product* processObject(const QDomElement& prod);
    std::vector<product::Product*> XMLReader(const QString& filePath);
}
#endif