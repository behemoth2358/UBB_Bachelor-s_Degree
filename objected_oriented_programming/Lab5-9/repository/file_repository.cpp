#include "file_repository.h"

FileRepository::FileRepository(const std::string& data_file, const std::string& user_file) {

	this->data_file = data_file;
	this->user_file = user_file;

	FileRepository::load_data();
}

void FileRepository::load_data() {

	std::ifstream in( this->data_file.data() );

	int n;
	in >> n;
	in.get();

	for(int i = 0; i < n; i++) {
		std::string s;
		std::getline(in, s);

		std::vector< std::string > fields = split(s, ';');
		this->movies.push_back( Movie(fields[0], fields[1], fields[2], std::stoi(fields[3]), std::stoi(fields[4]) ) );
	}

	in.close();
	std::ifstream inn( this->user_file.data() );

	int m;
	inn >> m;
	for(int i = 0; i < m; i++) {
		int movie_index;
		inn >> movie_index;

		this->watchlist.push_back( movie_index );
	}

	inn.close();
}

void FileRepository::save_data() {

	std::ofstream out( this->data_file.data() );

	out << this->movies.size() << '\n';

	for(auto it: this->movies) {
		
		out << it.toCSV() << '\n';
	}

	out.close();
	std::ofstream outt( this->user_file.data() );

	outt << this->watchlist.size() << '\n';
	for(auto it: this->watchlist) {
		outt << it << '\n';
	}

	outt.close();
}

void FileRepository::add(const Movie& movie) {
	Repository::add( movie );
	FileRepository::save_data();
}

void FileRepository::erase(const Movie& movie) {
	Repository::erase( movie );
	FileRepository::save_data();
}

void FileRepository::add_movie_to_watchlist(size_t movie_index) {
	Repository::add_movie_to_watchlist( movie_index );
	FileRepository::save_data();
}

void FileRepository::increment_likes(size_t movie_index) {
	Repository::increment_likes( movie_index );
	FileRepository::save_data();
}

void FileRepository::erase_movie_from_watchlist(size_t movie_index) {
	Repository::erase_movie_from_watchlist( movie_index );
	FileRepository::save_data();
}