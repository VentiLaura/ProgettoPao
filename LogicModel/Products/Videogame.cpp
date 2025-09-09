#include "Videogame.h"
namespace product {
Videogame::~Videogame() {}
Videogame::Videogame(std::vector<Console_type> compatible, std::string producer, std::vector<Genre> genre, std::string image, std::string name, double price, std::string idProduct, int availability): Product(image, name, price, idProduct, availability), Compatibility(compatible), Producer(producer), Genres(genre) {}
Videogame& Videogame::operator=(Videogame& v) {
    if (this != &v) {  // Protezione contro auto-assegnamento
        // Assegna i campi della classe base (Product)
        setName(v.getName());
        setPrice(v.getPrice());
        setIdProduct(v.getIdProduct());
        setImage(v.getImage());
        setAvailability(v.getAvailability());

        // Assegna i campi specifici di Videogame
        Producer = v.getProducer();
        Compatibility = v.getCompatibility();
        Genres = v.getGenres();
    }
    return *this;
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
void Videogame::accept(Visitor* v) {
        v->visitVideogame(this);
}
}