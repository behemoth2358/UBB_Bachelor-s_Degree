#include "controller.h"

Controller::Controller(VirtualRepository<Movie>* repository) {
    this->repository = repository;
}

void Controller::add_movie(const std::string& title, const std::string& genre, const std::string& trailer, int year, int likes) {
    if(repository->find( Movie( title, genre, trailer, year, likes ) ) != NOT_FOUND) {
        throw ControllerException("Movie already in the list!");
    }
    repository->add( Movie( title, genre, trailer, year, likes ) );
}

const std::vector<Movie>& Controller::get_movies() const {
    return repository->get_data();
}

size_t Controller::size() {
    return repository->size();
}

void Controller::erase_movie(const std::string& title, const std::string& genre, const std::string& trailer, int year, int likes = 0) {
    repository->erase( Movie( title, genre, trailer, year, likes ) );

}

std::vector<Movie> Controller::get_movies_by_genre( const std::string& genre ) const {
    if( genre.size() == 0 ) {
        return repository->get_data();
    }

    std::vector<Movie> aux;

    for(auto it: repository->get_data()) {
        if(it.get_genre() == genre) {
            aux.push_back( it );
        }
    }
    return aux;
}

const std::vector<size_t>& Controller::get_watchlist() const {
    return repository->get_watchlist();
}

void Controller::add_movie_to_watchlist(const Movie& movie) {
    int pos = repository->find_in_watchlist( movie );
    if(pos != NOT_FOUND) {
        throw ControllerException("Movie already in watchlist!");
    }
    repository->add_movie_to_watchlist( repository->find( movie ) );
}

void Controller::rate_movie(const Movie& movie) {
    int watchlist_pos = repository->find_in_watchlist( movie );
    int pos = repository->find( movie );
    if(watchlist_pos == NOT_FOUND || pos == NOT_FOUND) {
        throw ControllerException("Can't find movie!");
    }
    repository->increment_likes( pos );
    repository->erase_movie_from_watchlist( watchlist_pos );
}

void Controller::update_movie(const std::string& title1, const std::string& genre1, const std::string& trailer1, int year1, int likes1, const std::string& title2, const std::string& genre2, const std::string& trailer2, const std::string& year2, const std::string& likes2) {

    std::string title, genre, trailer;
    int year, likes;
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

    int pos = repository->find( Movie( title1, genre1, trailer1, year1, likes1 ) );
    if(pos == -1) {
        throw ControllerException("Can't find movie!");
    }
    repository->set_movie( pos, Movie( title, genre, trailer, year, likes) );
}
