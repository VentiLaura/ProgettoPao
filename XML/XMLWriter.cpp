#include "XMLWriter.h"
XMLWriter::XMLWriter(const QString& path) : filePath(path) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file)) {
        qWarning() << "Errore apertura/parsing XML. Documento nuovo creato.";
        doc.appendChild(doc.createElement("Catalog"));  // default root
    }
    file.close();

    root = doc.documentElement();
}


void XMLWriter::removeById(const std::string& id) {
    QDomNodeList products = root.childNodes();
    for (int i = 0; i < products.size(); ++i) {
        QDomElement prodElem = products.at(i).toElement();
        if (!prodElem.isNull() && prodElem.firstChildElement("IdProduct").text().toStdString() == id) {
            root.removeChild(products.at(i));
            break;
        }
    }
}

void XMLWriter::save() {
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QTextStream stream(&file);
        stream << doc.toString(4);  // indentato
        file.close();
    } else {
        qWarning() << "Errore scrittura file XML.";
    }
}

void XMLWriter::appendProduct(product::Product* p) {
    p->accept(this);  // crea productElement
    root.appendChild(productElement);  // lo aggiunge al documento
}



void XMLWriter::writeCommonFields(product::Product* p) {
    productElement.appendChild(doc.createElement("IdProduct")).appendChild(doc.createTextNode(QString::fromStdString(p->getIdProduct())));
    productElement.appendChild(doc.createElement("Image")).appendChild(doc.createTextNode(QString::fromStdString(p->getImage())));
    productElement.appendChild(doc.createElement("Price")).appendChild(doc.createTextNode(QString::number(p->getPrice(), 'f', 2)));
    productElement.appendChild(doc.createElement("Copies_available")).appendChild(doc.createTextNode(QString::number(p->getAvailability())));
}

void XMLWriter::visitAccessory(product::Accessory* p) {
    productElement = doc.createElement("Product");
    productElement.appendChild(doc.createElement("Type")).appendChild(doc.createTextNode(QString::fromStdString("Accessory")));
    writeCommonFields(p);
    productElement.appendChild(doc.createElement("Name")).appendChild(doc.createTextNode(QString::fromStdString(p->getName())));
    productElement.appendChild(doc.createElement("Height")).appendChild(doc.createTextNode(QString::number(p->getHeight())));
    productElement.appendChild(doc.createElement("Length")).appendChild(doc.createTextNode(QString::number(p->getLenght())));
    productElement.appendChild(doc.createElement("Depth")).appendChild(doc.createTextNode(QString::number(p->getDepth())));
    productElement.appendChild(doc.createElement("Weight")).appendChild(doc.createTextNode(QString::number(p->getWeight())));

    QDomElement compat = doc.createElement("Compatibility");
    for (auto c : p->getCompatibility()) {
        QDomElement cElem = doc.createElement("Console");
        cElem.appendChild(doc.createTextNode(QString::fromStdString(product::ConsoleTypeToString(c))));
        compat.appendChild(cElem);
    }
    productElement.appendChild(compat);
}

void XMLWriter::visitVideogame(product::Videogame* p) {
    productElement = doc.createElement("Product");
    productElement.appendChild(doc.createElement("Type")).appendChild(doc.createTextNode(QString::fromStdString("Videogame")));
    writeCommonFields(p);

    productElement.appendChild(doc.createElement("Name")).appendChild(doc.createTextNode(QString::fromStdString(p->getName())));
    productElement.appendChild(doc.createElement("Producer")).appendChild(doc.createTextNode(QString::fromStdString(p->getProducer())));

    QDomElement compat = doc.createElement("Compatibility");
    for (auto c : p->getCompatibility()) {
        QDomElement cElem = doc.createElement("Console");
        cElem.appendChild(doc.createTextNode(QString::fromStdString(product::ConsoleTypeToString(c))));
        compat.appendChild(cElem);
    }
    productElement.appendChild(compat);

    QDomElement genres = doc.createElement("Genres");
    for (auto g : p->getGenres()) {
        QDomElement gElem = doc.createElement("Genre");
        gElem.appendChild(doc.createTextNode(QString::fromStdString(product::GenreToString(g))));
        genres.appendChild(gElem);
    }
    productElement.appendChild(genres);
}

void XMLWriter::visitConsole(product::Console* p) {
    productElement = doc.createElement("Product");
    productElement.appendChild(doc.createElement("Type")).appendChild(doc.createTextNode(QString::fromStdString("Console")));
    writeCommonFields(p);

    productElement.appendChild(doc.createElement("Serie")).appendChild(doc.createTextNode(QString::fromStdString(product::ConsoleTypeToString(p->getSerie()))));
    productElement.appendChild(doc.createElement("Memory")).appendChild(doc.createTextNode(QString::fromStdString(p->getMemory())));
}

void XMLWriter::visitCollectible(product::Collectible* p) {
    productElement = doc.createElement("Product");
    productElement.appendChild(doc.createElement("Type")).appendChild(doc.createTextNode(QString::fromStdString("Collectible")));
    writeCommonFields(p);
    productElement.appendChild(doc.createElement("Name")).appendChild(doc.createTextNode(QString::fromStdString(p->getName())));
    productElement.appendChild(doc.createElement("Category")).appendChild(doc.createTextNode(QString::fromStdString(p->GetCategory())));
    productElement.appendChild(doc.createElement("Franchise")).appendChild(doc.createTextNode(QString::fromStdString(p->GetFranchise())));
    productElement.appendChild(doc.createElement("Producer")).appendChild(doc.createTextNode(QString::fromStdString(p->GetProducer())));
}

void XMLWriter::visitTshirt(product::T_shirt* p) {
    productElement = doc.createElement("Product");
    productElement.appendChild(doc.createElement("Type")).appendChild(doc.createTextNode(QString::fromStdString("T-shirt")));
    writeCommonFields(p);
    productElement.appendChild(doc.createElement("Name")).appendChild(doc.createTextNode(QString::fromStdString(p->getName())));
    productElement.appendChild(doc.createElement("Size")).appendChild(doc.createTextNode(QString::fromStdString(product::SizeToString(p->getSize()))));
    productElement.appendChild(doc.createElement("Franchise")).appendChild(doc.createTextNode(QString::fromStdString(p->getFranchise())));
}


/*void XMLWriter::RemoveByIdXML(const QString& filePath, const std::string& id) {
    QDomDocument doc;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file)) {
        qWarning() << "Errore lettura/parsing file XML";
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();
    QDomNodeList products = root.childNodes();

    for (int i = 0; i < products.size(); ++i) {
        QDomElement prodElem = products.at(i).toElement();
        if (!prodElem.isNull() && prodElem.firstChildElement("IdProduct").text().toStdString() == id) {
            root.removeChild(products.at(i));
            break;
        }
    }

    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QTextStream stream(&file);
        stream << doc.toString(4);
        file.close();
    } else {
        qWarning() << "Errore scrittura file XML";
    }
}*/

