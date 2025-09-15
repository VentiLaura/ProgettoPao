#include "JSONWriter.h"
namespace json {
JSONWriter::JSONWriter(const QString& path): filePath(path) {
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly)) {
        QJsonParseError error;
        QJsonDocument doc=QJsonDocument::fromJson(file.readAll(), &error);
        file.close();
        if(error.error==QJsonParseError::NoError && doc.isArray()) {
            array=doc.array();
        } else {
            qWarning()<<"Error in JSON parsing, empty initialization:" << error.errorString();
        }
    } else {
        qWarning()<<"File JSON not found, empty initialization.";
    }
}

void JSONWriter::removeById(const std::string& id) {
    for (int i=0; i<array.size(); ++i) {
        if (array[i].toObject()["IdProduct"].toString().toStdString()==id) {
            array.removeAt(i);
            break;
        }
    }
}

void JSONWriter::appendProduct(product::Product* p) {
    p->accept(this);            
    array.append(currentObject);
}

void JSONWriter::save() {
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QJsonDocument doc(array);
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
    } else {
        qWarning() << "Error in JSON writing";
    }
}

void JSONWriter::visitAccessory(product::Accessory* p) {
    currentObject=QJsonObject();
    currentObject["Type"]="Accessory";
    currentObject["IdProduct"]=QString::fromStdString(p->getIdProduct());
    currentObject["Name"]=QString::fromStdString(p->getName());
    currentObject["Image"]=QString::fromStdString(p->getImage());
    currentObject["Price"]=p->getPrice();
    currentObject["Copies_available"]=p->getAvailability();
    currentObject["Height"]=p->getHeight();
    currentObject["Lenght"]=p->getLenght();
    currentObject["Depth"]=p->getDepth();
    currentObject["Weight"]=p->getWeight();

    QJsonArray compat;
    for (auto c : p->getCompatibility()) {
        compat.append(QString::fromStdString(product::ConsoleTypeToString(c)));
    }
    currentObject["Compatibility"]=compat;
}

void JSONWriter::visitVideogame(product::Videogame* p) {
    currentObject=QJsonObject();
    currentObject["Type"]="Videogame";
    currentObject["IdProduct"]=QString::fromStdString(p->getIdProduct());
    currentObject["Name"]=QString::fromStdString(p->getName());
    currentObject["Image"]=QString::fromStdString(p->getImage());
    currentObject["Price"]=p->getPrice();
    currentObject["Copies_available"]=p->getAvailability();
    currentObject["Producer"]=QString::fromStdString(p->getProducer());

    QJsonArray genres;
    for(auto g : p->getGenres()) {
        genres.append(QString::fromStdString(product::GenreToString(g)));
    }
    currentObject["Genres"]=genres;

    QJsonArray compat;
    for(auto c : p->getCompatibility()) {
        compat.append(QString::fromStdString(product::ConsoleTypeToString(c)));
    }
    currentObject["Compatibility"] = compat;
}

void JSONWriter::visitConsole(product::Console* p) {
    currentObject=QJsonObject();
    currentObject["Type"]="Console";
    currentObject["IdProduct"]=QString::fromStdString(p->getIdProduct());
    currentObject["Image"]=QString::fromStdString(p->getImage());
    currentObject["Price"]=p->getPrice();
    currentObject["Copies_available"]=p->getAvailability();
    currentObject["Serie"]=QString::fromStdString(product::ConsoleTypeToString(p->getSerie()));
    currentObject["Memory"]=QString::fromStdString(p->getMemory());
}

void JSONWriter::visitCollectible(product::Collectible* p) {
    currentObject=QJsonObject();
    currentObject["Type"]="Collectible";
    currentObject["IdProduct"]=QString::fromStdString(p->getIdProduct());
    currentObject["Name"]=QString::fromStdString(p->getName());
    currentObject["Image"]=QString::fromStdString(p->getImage());
    currentObject["Price"]=p->getPrice();
    currentObject["Copies_available"]=p->getAvailability();
    currentObject["Category"]=QString::fromStdString(p->GetCategory());
    currentObject["Franchise"]=QString::fromStdString(p->GetFranchise());
    currentObject["Producer"]=QString::fromStdString(p->GetProducer());
}

void JSONWriter::visitTshirt(product::T_shirt* p) {
    currentObject=QJsonObject();
    currentObject["Type"]="T-shirt";
    currentObject["IdProduct"]=QString::fromStdString(p->getIdProduct());
    currentObject["Name"]=QString::fromStdString(p->getName());
    currentObject["Image"]=QString::fromStdString(p->getImage());
    currentObject["Price"]=p->getPrice();
    currentObject["Copies_available"]=p->getAvailability();
    currentObject["Size"]=QString::fromStdString(product::SizeToString(p->getSize()));
    currentObject["Franchise"]=QString::fromStdString(p->getFranchise());
}
}