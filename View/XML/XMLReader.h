#ifndef XMLREADER_H
#define XMLREADER_H
#include "../../LogicModel/Products/Product.h"
#include <vector>
#include <QString>
#include <QDomDocument>

namespace xml { 
    product::Product* processObject(const QDomElement& elem);
    std::vector<product::Product*> XmlReader(const QString& filePath);
}
#endif