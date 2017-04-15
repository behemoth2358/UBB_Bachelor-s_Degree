#ifndef DOMAIN_H
#define DOMAIN_H

#include <string>

class Movie{
private:
    std::string title, genre, trailer;
    int year, likes;

public:
    Movie(std::string, std::string, std::string, int, int);
    Movie();
    bool operator==(const Movie& other) const
    {
        return (this->title==other.title && this->genre==other.genre && this->year==other.year);// && this->likes==other.getLikes() );
    }
    std::string getTitle();
    std::string getGenre();
    std::string getTrailer();
    int getYear();
    int getLikes();
    void setTitle(std::string);
    void setGenre(std::string);
    void setTrailer(std::string);
    void setYear(int);
    void setLikes(int);
    std::string toString();
};

#endif
