#include "Videogame.h"
namespace product {
Videogame::~Videogame() {}
Videogame::Videogame(std::vector<Console_type> compatible, std::string producer, std::vector<Genre> genre, double price, std::string name, std::string idProduct, int availability): Product(price, idProduct, availability), Name(name), Compatibility(compatible), Producer(producer), Genres(genre) {}
std::string Videogame::getName() const {
    return Name;
}
void Videogame::setName(std::string n) {
    Name=n;
}
void Videogame::setGenre(std::vector<Genre> g) {
    Genres=g;
}
bool Videogame::IsCompatible(Console_type console) const {
    for(std::vector<Console_type>::const_iterator it=Compatibility.begin(); it!=Compatibility.end(); it++) {
        if((*it)==console) return true;
    }
    return false;
}
bool Videogame::IsGenre(Genre g) const {
    for(std::vector<Genre>::const_iterator it=Genres.begin(); it!=Genres.end(); it++) {
        if((*it)==g) return true;
    }
    return false;
}
const std::vector<Genre>& Videogame::getGenres() const {
    return Genres;
}
const std::vector<Console_type>& Videogame::getCompatibility() const {
    return Compatibility;
}

std::string Videogame::getProducer() const {
    return Producer;
}

void Videogame::setProducer(std::string producer) {
    Producer=producer;
}
void Videogame::setCompatibility(std::vector<Console_type>& c) {
    Compatibility=c;
}
}