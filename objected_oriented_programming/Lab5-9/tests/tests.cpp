#include "tests.h"

void Tests::test_domain() {
	Movie movie(std::string("test"), std::string("test"), std::string("test"), 0, 0);

	assert( movie.get_title() == "test" );
	assert( movie.get_genre() == "test" );
	assert( movie.get_trailer() == "test" );
	assert( movie.get_year() == 0 );
	assert( movie.get_likes() == 0 );
	movie.set_title("test2");
	assert( movie.get_title() == "test2" );
	movie.set_genre("test2");
	assert( movie.get_genre() == "test2" );
	movie.set_trailer("test2");
	assert( movie.get_trailer() == "test2" );
	movie.set_year(1);
	assert( movie.get_year() == 1 );
	movie.set_likes(1);
	assert( movie.get_likes() == 1 );
}

void Tests::test_repository() {
	Repository repo;
	Movie movie(std::string("test"), std::string("test"), std::string("test"), 0, 0);
	repo.add( movie );
	assert( repo.size() == 1 );
	assert( repo.find( movie ) != NOT_FOUND );
	assert( repo.get_data().size() == 1);
	assert( repo.find_in_watchlist( movie ) == NOT_FOUND);
	repo.add_movie_to_watchlist( repo.find(movie) );
	assert( repo.get_watchlist().size() == 1);
	repo.increment_likes( repo.find( movie ) );
	repo.erase_movie_from_watchlist( repo.find( movie ) );
	assert( repo.get_watchlist().size() == 0);
}

void Tests::test_controller() {
	Repository repo;
	Controller cont(&repo);
	Movie movie(std::string("test"), std::string("test"), std::string("test"), 0, 0);
	cont.add_movie( std::string("test"), std::string("test"), std::string("test"), 0, 0 );
	assert( cont.size() == 1 );
	assert( cont.get_movies().size() == 1 );
	assert( cont.get_movies() == cont.get_movies_by_genre( std::string("test") ) );
	try {
		cont.add_movie( std::string("test"), std::string("test"), std::string("test"), 0, 0 );
		assert( false );
	} catch (const std::exception& err) {
        assert( true );
    }

    Movie movie1(std::string("test1"), std::string("test1"), std::string("test1"), 0, 0);
    cont.add_movie( std::string("test1"), std::string("test1"), std::string("test1"), 0, 0 );
    cont.erase_movie( std::string("test1"), std::string("test1"), std::string("test1"), 0, 0 );
    assert( cont.size() == 1 );
    assert( cont.get_watchlist().size() == 0 );
    cont.add_movie_to_watchlist( movie );
    assert( cont.get_watchlist().size() == 1 );
    cont.rate_movie( movie );
    assert( cont.get_watchlist().size() == 0 );
}

void Tests::run_tests() {
	Tests::test_controller();
	Tests::test_repository();
	Tests::test_domain();
}