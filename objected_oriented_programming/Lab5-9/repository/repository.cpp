#include "repository.h"

void Repository::add(const Movie& movie) {
    this->movies.push_back( movie );
}

void Repository::erase(const Movie& movie) {
    if( find_in_watchlist( movie ) != NOT_FOUND ) {
        erase_movie_from_watchlist( find_in_watchlist( movie ) );
    }
    this->movies.erase( std::find( this->movies.begin(), this->movies.end(), movie) );
}

int Repository::find(const Movie& movie) {
    for(size_t i = 0; i < this->movies.size(); i++) {
        if(this->movies[ i ] == movie) {
            return i;
        }
    }
    return NOT_FOUND;
}

void Repository::set_movie(size_t pos, const Movie& new_movie) {
    this->movies[ pos ] = new_movie;
}

size_t Repository::size() {
    return this->movies.size();
}

const std::vector<Movie>& Repository::get_data() const {
    return this->movies;
}

int Repository::find_in_watchlist(const Movie& movie) {
    for(size_t i = 0; i < this->watchlist.size(); i++) {
        if(this->movies[ this->watchlist[ i ] ] == movie) {
            return i;
        }
    }
    return NOT_FOUND;
}

void Repository::add_movie_to_watchlist(size_t pos) {
    this->watchlist.push_back( pos );
}

void Repository::increment_likes(size_t pos) {
    this->movies[ pos ].set_likes( this->movies[ pos ].get_likes() + 1 );
}

void Repository::erase_movie_from_watchlist(size_t pos) {
    watchlist.erase( watchlist.begin() + pos );
}

const std::vector<size_t>& Repository::get_watchlist() const {
    return this->watchlist;
}
