#ifndef JSONREADER_H
#define JSONREADER_H
#include "../Products/Product.h"
#include <QFile> 
#include <QJsonDocument> 
#include <QJsonObject> 
#include <QJsonArray> 
#include <QDebug>
namespace json {
product::Product* processObject(const QJsonObject&);
std::vector<product::Product*> JsonReader(const QString&);
}
#endif