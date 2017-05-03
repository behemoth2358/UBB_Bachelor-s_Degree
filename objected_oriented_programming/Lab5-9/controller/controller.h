#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../domain/movie.h"
#include "../repository/repository.h"
#include "../repository/virtual_repository.h"
#include "../repository/file_repository.h"
#include "../utilities/constants.h"
#include "../exceptions/controller_exception.h"

#include <string>
#include <algorithm>

class Controller {

private:

    VirtualRepository<Movie>* repository;

public:

    Controller(){}

    Controller(VirtualRepository<Movie>*);

    void add_movie(const std::string&, const std::string&, const std::string&, int, int);

    const std::vector<Movie>& get_movies() const;

    size_t size();

    void erase_movie(const std::string&, const std::string&, const std::string&, int, int);

    void update_movie(const std::string&, const std::string&, const std::string&, int, int, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
    
    std::vector<Movie> get_movies_by_genre(const std::string&) const;
    
    const std::vector<size_t>& get_watchlist() const;
    
    void rate_movie(const Movie&);
    
    void add_movie_to_watchlist(const Movie&);
};

#endif
