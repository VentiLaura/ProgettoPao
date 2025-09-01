#ifndef CONSOLE_CPP
#define CONSOLE_CPP
#include "Console.h"
namespace product {
Console::Console(Console_type c, double p, std::string id, int av): Product(p, id, av), Serie(c) {}
Console::~Console() {}
Console_type Console::getSerie() const {
    return Serie;
}
void Console::setSerie(Console_type& c) {
    Serie=c;
}
}
#endif