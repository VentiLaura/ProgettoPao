#ifndef CONSOLE_CPP
#define CONSOLE_CPP
#include "Console.h"
namespace product {
Console::Console(Console_type c, std::string m, std::string i, double p, std::string id, int av): Product(i, ConsoleTypeToString(c), p, id, av), Serie(c), Memory(m) {}
Console::~Console() {}
Console_type Console::getSerie() const {
    return Serie;
}
void Console::setSerie(Console_type c) {
    Serie=c;
}

std::string Console::getMemory() const {
    return Memory;
}
void Console::setMemory(std::string m) {
    Memory=m;
}
void Console::accept(Visitor* v) {
    v->visitConsole(this);
}
Console& Console::operator=(Console& c) {
    setName(c.getName());
    setPrice(c.getPrice());
    setIdProduct(c.getIdProduct());
    setImage(c.getImage());
    setAvailability(c.getAvailability());
    Memory = c.getMemory();
    Serie = c.getSerie();
    return *this;
}
}
#endif