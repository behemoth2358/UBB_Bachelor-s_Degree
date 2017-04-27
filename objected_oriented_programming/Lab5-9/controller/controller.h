#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../repository/repository.h"

#include <string>
#include <algorithm>

class Controller {

private:

    Repository repository;

public:

    Controller(){}
    Controller(const Repository&);
    void add_movie(std::string, std::string, std::string, int, int);
    std::vector< Movie > get_movies();
    size_t size();
    void erase_movie(std::string, std::string, std::string, int, int);
    void update_movie(std::string, std::string, std::string, int, int,std::string, std::string, std::string, std::string, std::string);
    std::vector< Movie > get_movies_by_genre(std::string);
    std::vector<int> get_watchlist();
    void rate_movie(const Movie&);
    void add_movie_to_watchlist(const Movie&);
};

#endif
