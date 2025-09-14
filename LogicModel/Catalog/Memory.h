#ifndef MEMORY_H
#define MEMORY_H
#include "../Products/IncludeAllProducts.h"
#include <vector>
#include <QString>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include "Memory.h"
#include <string>
#include <stdexcept>
#include "../../XML/XMLWriter.h"
#include "../../XML/XMLReader.h"
#include "../../JSON/JSONWriter.h"
#include "../../JSON/JSONReader.h"
namespace memory {
class Memory {
    private:
    std::vector<product::Product*> Catalog;
    Memory();
    Memory(std::vector<product::Product*>);     //questa potrebbe essere inutile
    Memory& operator=(Memory&)=delete;
    Memory(Memory&)=delete;
    void UpdateXML(const QString&, const std::string&, product::Product*);
    void UpdateJSON(const QString&, const std::string&, product::Product*);
    public:
    void RemoveFromJSON(const QString&, const std::string&);
    void RemoveFromXML(const QString&, const std::string&);
    void AddToXML(const QString& xmlPath, product::Product* p);
    void AddToJSON(const QString& jsonPath, product::Product* p);
    Memory& LoadFromFile(const QString& filePath);
    bool IsUnique(const std::string&);
    static Memory& getCentralMemoryInstance();
    Memory& Add(product::Product*);
    Memory& Add(std::vector<product::Product*>);
    Memory& Remove(std::string); 
    std::vector<product::Product*> getCatalog();
    Memory& UpdateProduct(std::string, product::Product*);
    std::vector<product::Product*>::iterator Find(std::string); 
};
}
#endif
