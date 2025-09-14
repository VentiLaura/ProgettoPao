#ifndef JSONREADER_H
#define JSONREADER_H  
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
namespace json {
product::Product* processObject(const QJsonObject&);
std::vector<product::Product*> JsonReader(const QString&);
}
#endif