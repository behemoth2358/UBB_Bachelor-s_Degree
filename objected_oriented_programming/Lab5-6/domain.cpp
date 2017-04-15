#include "domain.h"

Movie::Movie(std::string title, std::string genre, std::string trailer, int year, int likes)
{
    this->title=title;
    this->genre=genre;
    this->trailer=trailer;
    this->year=year;
    this->likes=likes;
}

Movie::Movie(){}
std::string Movie::getTitle()
{
    return this->title;
}

std::string Movie::getGenre()
{
    return this->genre;
}

std::string Movie::getTrailer()
{
    return this->trailer;
}

int Movie::getYear()
{
    return this->year;
}

int Movie::getLikes()
{
    return this->likes;
}

void Movie::setTitle(std::string title)
{
    this->title=title;
}

void Movie::setGenre(std::string genre)
{
    this->genre=genre;
}

void Movie::setTrailer(std::string trailer)
{
    this->trailer=trailer;
}

void Movie::setYear(int year)
{
    this->year=year;
}

void Movie::setLikes(int likes)
{
    this->likes=likes;
}

std::string Movie::toString()
{
    std::string out("");
    out+="\nTitle: ";
    out+=this->title;
    out+="\nGenre: ";
    out+=this->genre;
    out+="\nTrailer: ";
    out+=this->trailer;
    out+="\nYear: ";
    out+=std::to_string(this->year);
    out+="\nNumber of likes: ";
    out+=std::to_string(this->likes);
    out+="\n";
    return out;
}
