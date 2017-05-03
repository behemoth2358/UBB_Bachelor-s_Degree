#ifndef VIRTUAL_REPOSITORY_H
#define VIRTUAL_REPOSITORY_H

#include <vector>
#include <fstream>
#include <string>

template< typename T >
class VirtualRepository {
public:
	
	virtual void load_data() = 0;

    virtual void save_data() = 0;

    virtual void add(const T& obj) = 0;

    virtual void erase(const T &obj) = 0;

    virtual int find(const T &obj) = 0;

    virtual const std::vector<T>& get_data() const = 0;

    virtual size_t size() = 0;

    virtual void set_movie(size_t, const T&) = 0;

    virtual const std::vector<size_t>& get_watchlist() const = 0;

    virtual void add_movie_to_watchlist(size_t) = 0;

    virtual int find_in_watchlist(const T&) = 0;

    virtual void increment_likes(size_t) = 0;

    virtual void erase_movie_from_watchlist(size_t) = 0;
};

#endif
