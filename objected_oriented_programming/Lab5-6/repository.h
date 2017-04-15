#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "vector.h"
#include "domain.h"
#include <fstream>
#include <string>

class Repository{
private:
    vector<Movie> movies;
    vector<int> watchlist;
   // std::string file,user;
public:
    Repository()
    {
        this->movies.clear();
        this->watchlist.clear();
    }
    Repository(const Repository&);
  //  Repository(std::string, std::string);
  //  void load_data();
  //  void save_data();
    void addMovie(Movie);
    vector<Movie> getMovies() const;
    size_t nrOfMovies();
    Movie getMovie(size_t);
    void setMovie(size_t, Movie);
    int findMovie(Movie);
    void eraseMovie(size_t);
    vector<int> getWatchlist() const;
    void addMovieToWatchlist(int);
    int findInWatchlist(Movie);
    void incrementLikes(int);
    void eraseMovieFromWatchlist(int);
    void clearMovies();
    void clearWatchlist();
};

#endif
