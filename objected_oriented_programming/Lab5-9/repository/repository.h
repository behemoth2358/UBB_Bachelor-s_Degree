#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "../domain/movie.h"

#include <vector>
#include <fstream>
#include <string>

class Repository{

private:

    std::vector< Movie > movies;
    std::vector<int> watchlist;

public:

    Repository(){}
    void _add_movie(const Movie&);
    std::vector< Movie > _get_movies();
    size_t size();
    Movie _get_movie(size_t);
    void _set_movie(size_t, const Movie&);
    int _find_movie(const Movie&);
    void _erase_movie(size_t);
    std::vector<int> _get_watchlist();
    void _add_movie_to_watchlist(int);
    int _find_in_watchlist(const Movie&);
    void _increment_likes(int);
    void _erase_movie_from_watchlist(int);
};

#endif
