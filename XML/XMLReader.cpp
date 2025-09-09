#include "XMLReader.h"
#include "../LogicModel/Products/IncludeAllProducts.h"
#include <QFile>
#include <QtXml/QDomDocument>
//#include <QtXml/QDomElement>
#include <QDebug>
#include <QJsonParseError>


using namespace product;

namespace xml {

    Product* processObject(const QDomElement& prod) {

        QString type = QString::fromStdString(prod.firstChildElement("Type").text().toStdString()); 
         if (type == "Accessory") {
        std::string image = prod.firstChildElement("Image").text().toStdString();
        std::string name = prod.firstChildElement("Name").text().toStdString();
        double price = prod.firstChildElement("Price").text().toDouble();
        std::string id = prod.firstChildElement("IdProduct").text().toStdString();
        int availability = prod.firstChildElement("Copies_available").text().toInt();
        double height = prod.firstChildElement("Height").text().toDouble();
        double length = prod.firstChildElement("Length").text().toDouble();
        double depth = prod.firstChildElement("Depth").text().toDouble();
        double weight = prod.firstChildElement("Weight").text().toDouble();

        std::vector<Console_type> compatibility;
        QDomNodeList compatList = prod.firstChildElement("Compatibility").elementsByTagName("Console");
        for (int i = 0; i < compatList.size(); ++i) {
            compatibility.push_back(StringToConsoleType(compatList.at(i).toElement().text().toStdString()));
        }

        return new Accessory(height, length, depth, weight, compatibility, image, name, price, id, availability);
    } else if (type == "Videogame") {
        std::string image = prod.firstChildElement("Image").text().toStdString();
        std::string name = prod.firstChildElement("Name").text().toStdString();
        double price = prod.firstChildElement("Price").text().toDouble();
        std::string id = prod.firstChildElement("IdProduct").text().toStdString();
        int availability = prod.firstChildElement("Copies_available").text().toInt();

        std::vector<Console_type> compatibility;
        QDomNodeList compatList = prod.firstChildElement("Compatibility").elementsByTagName("Console");
        for (int i = 0; i < compatList.size(); ++i) {
            compatibility.push_back(StringToConsoleType(compatList.at(i).toElement().text().toStdString()));
        }

        std::string producer = prod.firstChildElement("Producer").text().toStdString();
        std::vector<Genre> genres;
        QDomNodeList genreList = prod.firstChildElement("Genres").elementsByTagName("Genre");
        for (int i = 0; i < genreList.size(); ++i) {
            genres.push_back(StringToGenre(genreList.at(i).toElement().text().toStdString()));
        }

        return new Videogame(compatibility, producer, genres, image, name, price, id, availability);   
    } else if (type == "Console") {
        std::string image = prod.firstChildElement("Image").text().toStdString();
        std::string memory = prod.firstChildElement("Memory").text().toStdString();
        double price = prod.firstChildElement("Price").text().toDouble();
        std::string id = prod.firstChildElement("IdProduct").text().toStdString();
        int availability = prod.firstChildElement("Copies_available").text().toInt();
        Console_type serie = StringToConsoleType(prod.firstChildElement("Serie").text().toStdString());

        return new Console(serie, memory, image, price, id, availability);

    } else if (type == "Collectible") {
        std::string image = prod.firstChildElement("Image").text().toStdString();
        std::string name = prod.firstChildElement("Name").text().toStdString();
        double price = prod.firstChildElement("Price").text().toDouble();
        std::string id = prod.firstChildElement("IdProduct").text().toStdString();
        int availability = prod.firstChildElement("Copies_available").text().toInt();
        std::string category = prod.firstChildElement("Category").text().toStdString();
        std::string franchise = prod.firstChildElement("Franchise").text().toStdString();
        std::string producer = prod.firstChildElement("Producer").text().toStdString();

        return new Collectible(category, franchise, producer, image, name, price, id, availability);

    } else if (type == "T-shirt") {
        std::string image = prod.firstChildElement("Image").text().toStdString();
        std::string name = prod.firstChildElement("Name").text().toStdString();
        double price = prod.firstChildElement("Price").text().toDouble();
        std::string id = prod.firstChildElement("IdProduct").text().toStdString();
        int availability = prod.firstChildElement("Copies_available").text().toInt();
        Sizes size = StringToSize(prod.firstChildElement("Size").text().toStdString());
        std::string franchise = prod.firstChildElement("Franchise").text().toStdString();

        return new T_shirt(size, franchise, image, name, price, id, availability);
    }

    qWarning() << "Type not recognised:" << type;
    return nullptr;
}

std::vector<Product*> XMLReader(const QString& filePath) {
    std::vector<Product*> products;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Error during opening of file XML";
        return products;
    }

    QJsonParseError error;
    QDomDocument doc;
    if (!doc.setContent(&file)) {
        qWarning() << "Error during XML parsing:"<< error.errorString();;
        file.close();
        return products;
    }

    file.close();

    QDomElement root = doc.documentElement();
    QDomNodeList productNodes = root.childNodes();

    for (int i = 0; i < productNodes.size(); ++i) {
        QDomElement elem = productNodes.at(i).toElement();
        if (!elem.isNull()) {
            try {
                qDebug() << "Parsing elemento #" << i;
                Product* prod = processObject(elem);
                if (prod) products.push_back(prod);
            } catch (const std::exception& excep) {
                qWarning() << "Failed to create product" << excep.what();
            }
        }
    }

    return products;
}
}