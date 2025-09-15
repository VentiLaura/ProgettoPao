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
Console& Console::operator=(Product& c) {
    Console* console=dynamic_cast<Console*>(&c);
    if(!console) std::__throw_invalid_argument ("Assigned Product is not a console");
    setName(console->getName());
    setPrice(console->getPrice());
    setIdProduct(console->getIdProduct());
    setImage(console->getImage());
    setAvailability(console->getAvailability());
    Memory = console->getMemory();
    Serie = console->getSerie();
    return *this;
}
}
#endif