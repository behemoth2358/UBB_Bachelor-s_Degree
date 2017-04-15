#include "repository.h"

/*void Repository::load_data()
{
    std::ifstream in(file);
    size_t n;
    in>>n;
    for(size_t i=0;i<n;i++)
    {
        std::string title,genre,trailer;
        int year,likes;
        in.get();
        getline(in,title);
        getline(in,genre);
        getline(in,trailer);
        in>>year>>likes;
        movies.push_back( Movie(title, genre, trailer, year, likes) );
    }
    in.close();

    std::ifstream inn(user);
    size_t nn;
    inn>>nn;
    for(size_t i=0;i<nn;i++)
    {
        int x;
        inn>>x;
        watchlist.push_back(x);
    }
    inn.close();
}

void Repository::save_data()
{
    std::ofstream out(file);
    out<<movies.size()<<'\n';
    for(size_t i=0;i<movies.size();i++)
    {
        out<<movies[i].getTitle()<<'\n';
        out<<movies[i].getGenre()<<'\n';
        out<<movies[i].getTrailer()<<'\n';
        out<<movies[i].getYear()<<'\n';
        out<<movies[i].getLikes()<<'\n';
    }
    out.close();

    std::ofstream outt(user);
    outt<<watchlist.size()<<'\n';
    for(size_t i=0;i<watchlist.size();i++)
    {
        outt<<watchlist[i]<<'\n';
    }
    outt.close();
}*/

Repository::Repository(const Repository& other)
{
    this->movies.clear();
    this->watchlist.clear();
    this->movies = other.getMovies();
    this->watchlist = other.getWatchlist();
}


void Repository::addMovie(Movie movie)
{
    this->movies.push_back(movie);
   // save_data();
}

void Repository::clearMovies()
{
    this->movies.clear();
}

void Repository::clearWatchlist()
{
    this->watchlist.clear();
}

void Repository::eraseMovie(size_t index)
{
    //this->movies.erase(index);
    if(findInWatchlist(movies[index])!=-1)
    {
        eraseMovieFromWatchlist(findInWatchlist(movies[index]));
    }
    this->movies=this->movies-this->movies[ index ];
    //save_data();
}

int Repository::findMovie(Movie movie)
{
    for(size_t i = 0;i < this->movies.size(); i++)
    {
        if(this->movies[ i ] == movie)
        {
            return i;
        }
    }
    return -1;
}

Movie Repository::getMovie(size_t pos)
{
    return this->movies[pos];
}

void Repository::setMovie(size_t pos, Movie newMovie)
{
    this->movies[pos]=newMovie;
}

size_t Repository::nrOfMovies()
{
    return this->movies.size();
}

vector<Movie> Repository::getMovies() const
{
    return this->movies;
}

int Repository::findInWatchlist(Movie movie)
{
    for(size_t i=0;i<this->watchlist.size();i++)
    if(this->movies[ this->watchlist[i] ]==movie)
    {
        return i;
    }
    return -1;
}

void Repository::addMovieToWatchlist(int x)
{
    this->watchlist.push_back(x);
    //save_data();
}

void Repository::incrementLikes(int x)
{
    int y=1+this->movies[x].getLikes();
    this->movies[x].setLikes(y);//save_data();
}

void Repository::eraseMovieFromWatchlist(int x)
{
    watchlist.erase(x);
    //save_data();
}

vector<int> Repository::getWatchlist() const
{
    return this->watchlist;
}
