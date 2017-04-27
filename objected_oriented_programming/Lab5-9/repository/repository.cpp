#include "repository.h"

void Repository::_add_movie(const Movie& movie) {
    this->movies.push_back( movie );
}

void Repository::_erase_movie(size_t index) {
    if( _find_in_watchlist( movies[ index ] ) != -1) {
        _erase_movie_from_watchlist( _find_in_watchlist( movies[ index ] ) );
    }
    this->movies.erase( this->movies.begin()+index );
}

int Repository::_find_movie(const Movie& movie) {
    for(size_t i = 0; i < this->movies.size(); i++) {
        if(this->movies[ i ] == movie) {
            return i;
        }
    }
    return -1;
}

Movie Repository::_get_movie(size_t pos) {
    return this->movies[ pos ];
}

void Repository::_set_movie(size_t pos, const Movie& new_movie) {
    this->movies[ pos ] = new_movie;
}

size_t Repository::size() {
    return this->movies.size();
}

std::vector< Movie > Repository::_get_movies() {
    return this->movies;
}

int Repository::_find_in_watchlist(const Movie& movie) {
    for(size_t i = 0; i < this->watchlist.size(); i++) {
        if(this->movies[ this->watchlist[ i ] ] == movie) {
            return i;
        }
    }
    return -1;
}

void Repository::_add_movie_to_watchlist(int x) {
    this->watchlist.push_back( x );
}

void Repository::_increment_likes(int x) {
    this->movies[x].set_likes( this->movies[x].get_likes() + 1 );
}

void Repository::_erase_movie_from_watchlist(int x) {
    watchlist.erase( watchlist.begin()+x );
}

std::vector<int> Repository::_get_watchlist() {
    return this->watchlist;
}
