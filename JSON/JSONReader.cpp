#include <vector>
#include <iostream>
#include "../LogicModel/Products/IncludeAllProducts.h"
#include "../LogicModel/Catalog/Memory.h"
#include "JSONReader.h"
#include <QFile> 
#include <QJsonDocument> 
#include <QJsonObject> 
#include <QJsonArray> 
#include <QDebug>
#include <stdexcept>
using namespace product;
namespace json {
Product* processObject(const QJsonObject& obj) {
    QString type = obj["Type"].toString();
    qDebug()<<"entrato\n";
    if (type=="Accessory") {
        std::string image=(obj["Image"].toString().toStdString());
        std::string name=(obj["Name"].toString()).toStdString();
        double price=obj["Price"].toDouble();
        std::string id=obj["IdProduct"].toString().toStdString();
        int avaiability=obj["Copies_available"].toInt();
        double height=obj["Height"].toDouble();
        double lenght=obj["Lenght"].toDouble();
        double depth=obj["Depth"].toDouble();
        double weight=obj["Weight"].toDouble();
        QJsonArray ArrayCompatibility=obj["Compatibility"].toArray();
        std::vector<Console_type> compatibility;
        for (const QJsonValue& val : ArrayCompatibility) {
            compatibility.push_back(StringToConsoleType((val.toString()).toStdString()));
        }
        Accessory* accessory=new Accessory(height, lenght, depth, weight, compatibility, image, name, price, id, avaiability);
        return accessory;

    } else if (type == "Videogame") {
        std::string image=(obj["Image"].toString().toStdString());
        std::string name=(obj["Name"].toString()).toStdString();
        double price=obj["Price"].toDouble();
        std::string id=obj["IdProduct"].toString().toStdString();
        int avaiability=obj["Copies_available"].toInt();
        QJsonArray ArrayCompatibility=obj["Compatibility"].toArray();
        std::vector<Console_type> compatibility;
        for (const QJsonValue& val : ArrayCompatibility) {
            compatibility.push_back(StringToConsoleType((val.toString()).toStdString()));
        }
        std::string producer=(obj["Producer"].toString()).toStdString();
        std::vector<Genre> genres;
        QJsonArray ArrayGenres=obj["Genres"].toArray();
        for (const QJsonValue& val : ArrayGenres) {
            genres.push_back(StringToGenre((val.toString()).toStdString()));
        }
        Videogame* videogame=new Videogame(compatibility, producer, genres, image, name, price, id, avaiability);
        return videogame;
    } else if (type=="Console") {
        std::string image=(obj["Image"].toString().toStdString());
        //std::string name=(obj["Name"].toString()).toStdString();
        std::string memory=(obj["Memory"].toString().toStdString());
        double price=obj["Price"].toDouble();
        std::string id=obj["IdProduct"].toString().toStdString();
        int avaiability=obj["Copies_available"].toInt();
        Console_type serie=StringToConsoleType((obj["Serie"].toString()).toStdString());
        Console* console=new Console(serie, memory, image, price, id, avaiability);
        return console;
            } else if(type=="Collectible") {
                std::string image=(obj["Image"].toString().toStdString());
                std::string name=(obj["Name"].toString()).toStdString();
                double price=obj["Price"].toDouble();
                std::string id=obj["IdProduct"].toString().toStdString();
                int avaiability=obj["Copies_available"].toInt();
                std::string category=obj["Category"].toString().toStdString();
                std::string franchise=obj["Franchise"].toString().toStdString();
                std::string producer=obj["Producer"].toString().toStdString();
                Collectible* collectible=new Collectible(category, franchise, producer, image, name, price, id, avaiability);
                return collectible;
            } else if(type=="T-shirt") {
                std::string image=(obj["Image"].toString().toStdString());
                std::string name=(obj["Name"].toString()).toStdString();
                double price=obj["Price"].toDouble();
                std::string id=obj["IdProduct"].toString().toStdString();
                int avaiability=obj["Copies_available"].toInt();
                Sizes size=StringToSize(obj["Size"].toString().toStdString());
                std::string franchise=obj["Franchise"].toString().toStdString();
                T_shirt* shirt=new T_shirt(size,franchise,image,name,price,id,avaiability);
                return shirt;
                } else {
        throw std::invalid_argument("Not a Compatible Type of Product:" + type.toStdString());
    }
}

std::vector<Product*> JsonReader(const QString& path) {
    std::vector<Product*> ProductsRead;
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Error during opening of file JSON";
        return ProductsRead;
    }
    QByteArray data = file.readAll();
    file.close();
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data, &error);
    if(error.error!=QJsonParseError::NoError) {
        qWarning() << "Error during JSON parsing:" << error.errorString();
        return ProductsRead;
    }
    if(doc.isArray()) {
        QJsonArray array=doc.array();
        for (const QJsonValue& val : array) {
            if(val.isObject())
                ProductsRead.push_back(processObject(val.toObject()));
                
        }
        qDebug()<<ProductsRead.size();
    } else if(doc.isObject()) {
        ProductsRead.push_back(processObject(doc.object()));
    } else {
        qWarning() << "JSON format not valid";
    }
    return ProductsRead;
}
}