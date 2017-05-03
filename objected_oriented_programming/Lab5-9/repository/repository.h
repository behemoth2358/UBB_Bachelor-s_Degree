#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "virtual_repository.h"

#include "../domain/movie.h"
#include "../utilities/constants.h"
#include "../exceptions/controller_exception.h"


#include <vector>
#include <algorithm>
#include <string>

class Repository : public VirtualRepository<Movie> { 

public:

    std::vector<Movie> movies;
    
    std::vector<size_t> watchlist;

    void load_data(){}

    void save_data(){}

    Repository(){}

    ~Repository(){}

    void add(const Movie&);

    void erase(const Movie& obj);

    int find(const Movie& obj);

    const std::vector<Movie>& get_data() const;

    size_t size();

    void set_movie(size_t, const Movie&);

    const std::vector<size_t>& get_watchlist() const;

    void add_movie_to_watchlist(size_t);

    int find_in_watchlist(const Movie&);

    void increment_likes(size_t);

    void erase_movie_from_watchlist(size_t);
};

#endif
