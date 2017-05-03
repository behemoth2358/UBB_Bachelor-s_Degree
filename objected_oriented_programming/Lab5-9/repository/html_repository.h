#ifndef HTML_REPOSITORY_H
#define HTML_REPOSITORY_H

#include "virtual_repository.h"
#include "../exceptions/controller_exception.h"
#include "repository.h"
#include "file_repository.h"
#include "../domain/movie.h"
#include <fstream>
#include "../utilities/functions.h"

#include <fstream>

class HTMLRepository : public FileRepository {

public:

    std::string html_file;

    HTMLRepository(){}

	HTMLRepository(const std::string&, const std::string&, const std::string&);

    ~HTMLRepository(){}

    void save_data();

    void add_movie_to_watchlist(size_t);

    void erase_movie_from_watchlist(size_t);

};

#endif