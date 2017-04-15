#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "repository.h"
#include "vector.h"
#include <string>

class Controller{
private:
    Repository repository;
public:
    Controller();
    Controller(const Repository&);
    Controller(const Controller&);
    void AddMovie(std::string, std::string, std::string, int, int);
    vector<Movie> GetMovies() const;
    size_t NumberOfMovies();
    void EraseMovie(std::string, std::string, std::string, int, int);
    void UpdateMovie(std::string, std::string, std::string, int, int,std::string, std::string, std::string, std::string, std::string);
    vector<Movie> GetMoviesByGenre(std::string) const;
    vector<int> GetWatchlist() const;
    void RateMovie(Movie);
    void AddMovieToWatchlist(Movie);
};

#endif
