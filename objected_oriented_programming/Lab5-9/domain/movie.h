#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
private:
    
    std::string title, genre, trailer;
    int year, likes;

public:
    
    Movie() {}

    Movie(const std::string&, const std::string&, const std::string&, int, int);

    bool operator==(const Movie& other) const;

    std::string get_title() const;

    std::string get_genre() const;

    std::string get_trailer() const;

    int get_year() const;

    int get_likes() const;

    void set_title(const std::string&);

    void set_genre(const std::string&);

    void set_trailer(const std::string&);

    void set_year(int);

    void set_likes(int);

    std::string toString() const;
    
    std::string toCSV() const;
};

#endif
