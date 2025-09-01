#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include <vector>
#include <string>
#include "Enums.h"
#include "Product.h"
namespace product {
class Videogame: public Product {
    private:
    std::string Name;
    std::vector<Console_type> Compatibility;
    std::string Producer;
    std::vector<Genre> Genres;
    public:
    ~Videogame();
    Videogame(std::vector<Console_type>, std::string, std::vector<Genre>, double, std::string, unsigned int, int=1);
    std::string getName() const; 
    void setName(std::string);
    const std::vector<Console_type>& getCompatibility() const;
    bool IsCompatible(Console_type) const;
    void setCompatibility(std::vector<Console_type>&);
    std::string getProducer() const;
    void setProducer(std::string);
    const std::vector<Genre>& getGenres() const;
    bool IsGenre(Genre) const; //se appartiene a quel genere, ritorna true
    void setGenre(std::vector<Genre>);
};
}
#endif