#include "controller.h"

Controller::Controller(const Repository& repo) : repository(repo) {
}

Controller::Controller(const Controller& other)
{
    this->repository = other.repository;
}


void Controller::AddMovie(std::string title, std::string genre, std::string trailer, int year, int likes)
{
    if(repository.findMovie(Movie(title,genre,trailer,year,likes))!=-1)
    {
        throw std::invalid_argument("Movie already in the list!");
    }
    repository.addMovie(Movie(title,genre,trailer,year,likes));
}

vector<Movie> Controller::GetMovies() const
{
    return repository.getMovies();
}

size_t Controller::NumberOfMovies()
{
    return repository.nrOfMovies();
}

void Controller::EraseMovie(std::string title, std::string genre, std::string trailer, int year, int likes=0)
{
    int pos=repository.findMovie(Movie(title,genre,trailer,year,likes));
    if(pos==-1)
    {
        throw std::invalid_argument("Can't find movie!");
    }
    repository.eraseMovie(pos);

}

vector<Movie> Controller::GetMoviesByGenre(std::string genre) const
{
    if(genre.size()==0)
    {
        return repository.getMovies();
    }
    vector<Movie> v=repository.getMovies(),vv;

    for(int i=0;i<(int)v.size();i++)
    if(v[i].getGenre()==genre)
    {
        vv.push_back(v[i]);
    }
    return vv;
}

vector<int> Controller::GetWatchlist() const
{
    return repository.getWatchlist();
}

void Controller::AddMovieToWatchlist(Movie movie)
{
    int pos=repository.findInWatchlist(movie);
    if(pos!=-1)
    {
        throw std::invalid_argument("Movie already in watchlist!");
    }
    repository.addMovieToWatchlist( repository.findMovie(movie) );
}

void Controller::RateMovie(Movie movie)
{
    int pos1=repository.findInWatchlist(movie);
    int pos=repository.findMovie(movie);
    if(pos1==-1 || pos==-1)
    {
        throw std::invalid_argument("Can't find movie!");
    }
    repository.incrementLikes(pos);
    repository.eraseMovieFromWatchlist(pos1);
}

void Controller::UpdateMovie(std::string title1, std::string genre1, std::string trailer1, int year1, int likes1, std::string title2, std::string genre2, std::string trailer2, std::string year2, std::string likes2)
{
    std::string title, genre, trailer;
    int year,likes;
    if(title2.size())
    {
        title=title2;
    }
    else{
        title=title1;
    }

    if(genre2.size())
    {
        genre=genre2;
    }
    else{
        genre=genre1;
    }

    if(trailer2.size())
    {
        trailer=trailer2;
    }
    else{
        trailer=trailer1;
    }

    if(year2.size())
    {
        year=std::stoi(year2);
    }
    else{
        year=year1;
    }

    if(likes2.size())
    {
        likes=std::stoi(likes2);
    }
    else{
        likes=likes1;
    }

    int pos=repository.findMovie( Movie(title1,genre1,trailer1,year1,likes1) );
    if(pos==-1)
    {
        throw std::invalid_argument("Can't find movie!");
    }
    repository.setMovie(pos, Movie(title,genre,trailer,year,likes));
}
