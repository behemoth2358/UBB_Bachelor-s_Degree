#include "movie.h"

Movie::Movie(std::string title, std::string genre, std::string trailer, int year, int likes) {
    this->title = title;
    this->genre = genre;
    this->trailer = trailer;
    this->year = year;
    this->likes = likes;
}

bool Movie::operator==(const Movie& other) const {
    return ( this->title == other.title && this->genre == other.genre );
}

std::string Movie::get_title() const {
    return this->title;
}

std::string Movie::get_genre() const {
    return this->genre;
}

std::string Movie::get_trailer() const {
    return this->trailer;
}

int Movie::get_year() const {
    return this->year;
}

int Movie::get_likes() const {
    return this->likes;
}

void Movie::set_title(const std::string& title) {
    this->title = title;
}

void Movie::set_genre(const std::string& genre) {
    this->genre = genre;
}

void Movie::set_trailer(const std::string& trailer) {
    this->trailer = trailer;
}

void Movie::set_year(int year) {
    this->year = year;
}

void Movie::set_likes(int likes) {
    this->likes = likes;
}

std::string Movie::toString() const {
    std::string out("");
    out += "\nTitle: ";
    out += this->title;
    out += "\nGenre: ";
    out += this->genre;
    out += "\nTrailer: ";
    out += this->trailer;
    out += "\nYear: ";
    out += std::to_string( this->year );
    out += "\nNumber of likes: ";
    out += std::to_string( this->likes );
    out += "\n";
    return out;
}
