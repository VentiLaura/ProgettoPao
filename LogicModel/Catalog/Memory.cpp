#include "Memory.h"

namespace memory {

Memory& Memory::LoadFromFile(const QString& filePath) {
    // Svuota il catalogo esistente e libera memoria
    for (auto p : Catalog) {
        delete p;
    }
    Catalog.clear();

    
std::vector<product::Product*> ReadProducts;
    if (filePath.endsWith(".json", Qt::CaseInsensitive)) {
        ReadProducts = json::JsonReader(filePath);
        // Supponendo esista un JSONReader simile a JSONWriter
    } else if (filePath.endsWith(".xml", Qt::CaseInsensitive)) {
        ReadProducts=xml::XMLReader(filePath);
    } else {
        throw std::invalid_argument("Formato file non supportato. Deve essere JSON o XML.");
    }

    // Aggiunge i prodotti caricati al Catalog senza scrivere nulla su file
    for (auto p : ReadProducts) {
        Catalog.push_back(p);
    }

    return *this;
}


std::vector<product::Product*> Memory::getCatalog() {
    return Catalog;
}
Memory::Memory() {}
Memory::Memory(std::vector<product::Product*> c): Catalog(c) {}
Memory& Memory::getCentralMemoryInstance() {
    static Memory CentralMemory;
    return CentralMemory;
}
bool Memory::IsUnique(const std::string& id) {
    for(std::vector<product::Product*>::const_iterator it=Catalog.begin(); it!=Catalog.end(); it++) {
        if((*it)->getIdProduct()==id) return false;
    }
    return true;
}
Memory& Memory::Add(product::Product* product) {
    if(IsUnique(product->getIdProduct())) { 
        Catalog.push_back(product);
        AddToJSON("JSON/Products.json", product);
        AddToXML("XML/Products.xml", product);
        return *this;
    } else {
        throw std::invalid_argument("Elemento non inserito perché id equivalente: " + product->getIdProduct());
    }
}
Memory& Memory::Add(std::vector<product::Product*> products) {
    std::vector<std::string> errors;
    for(std::vector<product::Product*>::iterator it=products.begin(); it!=products.end(); it++) {
        if(IsUnique((*it)->getIdProduct())) {
            Catalog.push_back(*it);
            AddToJSON("JSON/Products.json", *it);
            AddToXML("XML/Products.xml", *it);
        } else {
            errors.push_back((*it)->getIdProduct()+"\n");
        }
    }
    if(errors.empty()) {
        return *this;
    } else {
        std::string Errors="";
        for(auto it=errors.begin(); it!=errors.end(); it++) {
            Errors=Errors+*it;
        }
        throw std::invalid_argument("Elemento/i non inserito/i perché id equivalente/i: " + Errors);
    }
}
Memory& Memory::Remove(std::string id) {
    auto it=Find(id);
    if(it==Catalog.end()) {
        std::__throw_invalid_argument("The id of the Product to delete does not exists in the Memory");
    } else {
        delete *it;
        Catalog.erase(it);
        RemoveFromXML("XML/Products.xml", id);
        RemoveFromJSON("JSON/Products.json", id);
        return *this;
    }
}
std::vector<product::Product*>::iterator Memory::Find(std::string id) {
    for(std::vector<product::Product*>::iterator it=Catalog.begin(); it!=Catalog.end(); it++) {
        if((*it)->getIdProduct()==id) {
            return it;
        }
    }
}
Memory& Memory::UpdateProduct(std::string id, product::Product* updatedProduct) {
    if(IsUnique(updatedProduct->getIdProduct())||updatedProduct->getIdProduct()==id) {
        auto it=Find(id);
        if(it!=Catalog.end()) {
        *(*(it))=*updatedProduct;
        UpdateXML("XML/Products.xml", id, updatedProduct);
        UpdateJSON("JSON/Products.json", id, updatedProduct);
        } else {
            std::__throw_invalid_argument("The id of the Product to update does not exists in the Memory");
        }
    } else {
        std::__throw_invalid_argument("The new id already exsists");
    }
    return *this;
}

void Memory::UpdateXML(const QString& filePath, const std::string& id, product::Product* updatedProduct) {
    XMLWriter writer(filePath);
    writer.removeById(id);               // rimuove
    writer.appendProduct(updatedProduct); // aggiunge
    writer.save();                       // salva su file
}




void Memory::UpdateJSON(const QString& filePath, const std::string& id, product::Product* updatedProduct) {
    JSONWriter writer(filePath);
    writer.removeById(id);
    writer.appendProduct(updatedProduct);
    writer.save();
}


void Memory::RemoveFromXML(const QString& filePath, const std::string& id) {
    XMLWriter xmlWriter(filePath);
    xmlWriter.removeById(id);
    xmlWriter.save();
}

void Memory::RemoveFromJSON(const QString& filePath, const std::string& id) {
    JSONWriter jsonWriter(filePath);
        jsonWriter.removeById(id);
        jsonWriter.save();
}


void memory::Memory::AddToXML(const QString& xmlPath, product::Product* p) {
    XMLWriter writer(xmlPath);
    writer.appendProduct(p); // visita e aggiunge
    writer.save();           // salva su file
}

void memory::Memory::AddToJSON(const QString& jsonPath, product::Product* p) {
    JSONWriter writer(jsonPath);
    writer.appendProduct(p); // visita e aggiunge
    writer.save();           // salva su file
}
}
