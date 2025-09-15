#ifndef XMLREADER_H
#define XMLREADER_H
#include <vector>
#include <QString>
#include <QtXml/QDomDocument>
#include "../LogicModel/Products/IncludeAllProducts.h"
#include <QFile>

namespace xml { 
    product::Product* processObject(const QDomElement& prod);
    std::vector<product::Product*> XMLReader(const QString& filePath);
}
#endif