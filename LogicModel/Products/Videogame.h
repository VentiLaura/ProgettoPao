#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include <vector>
#include <string>
#include "Enums.h"
#include "Product.h"
namespace product {
class Videogame: public Product {
    private:
    std::vector<Console_type> Compatibility;
    std::string Producer;
    std::vector<Genre> Genres;
    public:
    ~Videogame();
    Videogame(std::vector<Console_type>, std::string, std::vector<Genre>, std::string, std::string, double, std::string, int=1);
    Videogame& operator=(Videogame&);
    const std::vector<Console_type>& getCompatibility() const;
    bool IsCompatible(Console_type) const;
    void setCompatibility(std::vector<Console_type>&);
    std::string getProducer() const;
    void setProducer(std::string);
    const std::vector<Genre>& getGenres() const;
    bool IsGenre(Genre) const; //se appartiene a quel genere, ritorna true
    void setGenre(std::vector<Genre>);
    void accept(Visitor*);
};
}
#endif