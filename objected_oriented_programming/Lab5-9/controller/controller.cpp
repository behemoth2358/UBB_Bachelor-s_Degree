#include "controller.h"
#include <iostream>


Controller::Controller(const Repository& repository) {
    this->repository = repository;
}

void Controller::add_movie(std::string title, std::string genre, std::string trailer, int year, int likes, int duration)
{
    if(repository._find_movie( Movie( title, genre, trailer, year, likes, duration )) != -1) {
        throw std::invalid_argument("Movie already in the list!");
    }
    repository._add_movie( Movie( title, genre, trailer, year, likes, duration ) );
}

std::vector< Movie > Controller::get_movies() {
    return repository._get_movies();
}

size_t Controller::size() {
    return repository.size();
}

void Controller::erase_movie(std::string title, std::string genre, std::string trailer, int year, int likes=0, int duration=0)
{
    size_t pos = repository._find_movie( Movie( title, genre, trailer, year, likes, duration ) );
    if(pos == -1){
        throw std::invalid_argument("Can't find movie!");
    }
    repository._erase_movie( pos );

}

std::vector< Movie > Controller::get_movies_by_genre( std::string genre )
{
    if( genre.size() == 0 ) {
        return repository._get_movies();
    }
    std::vector< Movie > v = repository._get_movies(), aux;

    for(size_t i = 0; i < v.size(); i++) {
        if(v[ i ].get_genre() == genre) {
            aux.push_back( v[ i ] );
        }
    }
    return aux;
}

std::vector<int> Controller::get_watchlist() {
    return repository._get_watchlist();
}

void Controller::add_movie_to_watchlist(const Movie& movie) {
    int pos = repository._find_in_watchlist( movie );
    if(pos != -1) {
        throw std::invalid_argument("Movie already in watchlist!");
    }
    repository._add_movie_to_watchlist( repository._find_movie( movie ) );
}

void Controller::rate_movie(const Movie& movie) {
    int watchlist_pos = repository._find_in_watchlist( movie );
    int pos = repository._find_movie( movie );
    if(watchlist_pos == -1 || pos == -1) {
        throw std::invalid_argument("Can't find movie!");
    }
    repository._increment_likes( pos );
    repository._erase_movie_from_watchlist( watchlist_pos );
}

void Controller::update_movie(std::string title1, std::string genre1, std::string trailer1, int year1, int likes1, std::string title2, std::string genre2, std::string trailer2, std::string year2, std::string likes2) {

    std::string title, genre, trailer;
    int year,likes;
    if( title2.size() ) {
        title = title2;
    }
    else {
        title = title1;
    }

    if( genre2.size() ) {
        genre = genre2;
    }
    else{
        genre = genre1;
    }

    if( trailer2.size() ) {
        trailer = trailer2;
    }
    else{
        trailer = trailer1;
    }
    if( year2.size() ) {
        year = std::stoi(year2);
    }
    else{
        year = year1;
    }
    if(likes2.size()) {
        likes = std::stoi(likes2);
    }
    else{
        likes = likes1;
    }

    int pos = repository._find_movie( Movie(title1,genre1,trailer1,year1,likes1,0) );
    if(pos == -1) {
        throw std::invalid_argument("Can't find movie!");
    }
    repository._set_movie( pos, Movie( title, genre, trailer, year, likes, 0 ) );
}
