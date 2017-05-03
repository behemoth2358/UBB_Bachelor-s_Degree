#ifndef FILE_REPOSITORY_H
#define FILE_REPOSITORY_H

#include "virtual_repository.h"
#include "../exceptions/controller_exception.h"
#include "repository.h"
#include "../domain/movie.h"
#include "../utilities/functions.h"

#include <fstream>

class FileRepository : public Repository {
    
public:

    std::string data_file, user_file;

	void load_data();

    void save_data();
    
    FileRepository(){}

	FileRepository(const std::string&, const std::string&);

    ~FileRepository(){}

    void add(const Movie&);

    void erase(const Movie&);

    void add_movie_to_watchlist(size_t);

    void increment_likes(size_t);

    void erase_movie_from_watchlist(size_t);
};

#endif