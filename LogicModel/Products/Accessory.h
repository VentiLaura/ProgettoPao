#ifndef ACCESSORY_H
#define ACCESSORY_H
#include "Product.h"
#include <vector>
#include "Enums.h"
//#include "../../View/Visitor/visitor.h"
namespace product {
class Accessory: public Product {
    private:
    double Height;
    double Lenght;
    double Depth;
    double Weight;
    std::vector<Console_type> Compatibility;
    public:
    Accessory(double, double, double, double, std::vector<Console_type>, std::string, std::string, double, std::string, int=1);
    ~Accessory();
    Accessory& operator=(Product&);
    double getHeight() const;
    void setHeight(double);
    double getLenght() const;
    void setLenght(double);
    double getDepth() const;
    void setDepth(double);
    double getWeight() const;
    void setWeight(double);
    bool IsCompatible(Console_type) const;
    const std::vector<Console_type> getCompatibility() const;
    void setCompatibility(std::vector<Console_type>&);
    void accept(Visitor*);
};
}
#endif