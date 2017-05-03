#include "html_repository.h"

HTMLRepository::HTMLRepository(const std::string& data_file, const std::string& user_file, const std::string& html_file) {

	this->data_file = data_file;
	this->user_file = user_file;

	this->html_file = html_file;

	FileRepository::load_data();
}

void HTMLRepository::save_data() {
	FileRepository::save_data();

	std::ofstream out( this->html_file.data() );

	out << "<!DOCTYPE html>\n";
	out << "<html>\n";
	out << "	<head>\n";
	out << "		<title>Watchlist</title>\n";
	out << "	</head>\n";
	out << "	<body>\n";
	out << "		<table border=\"1\">";


	out << "		<tr>\n";
	out << "			<td>" << "Title" << "</td>\n";
	out << "			<td>" << "Genre" << "</td>\n";
	out << "			<td>" << "Year" << "</td>\n";
	out << "			<td>" << "Likes" << "</td>\n";
	out << "			<td>" << "Trailer" << "</td>\n";
	out << "	</tr>\n";

	for(auto it: this->watchlist) {
		out << "		<tr>\n";
		out << "			<td>" << this->movies[ it ].get_title() << "</td>\n";
		out << "			<td>" << this->movies[ it ].get_genre() << "</td>\n";
		out << "			<td>" << this->movies[ it ].get_year() << "</td>\n";
		out << "			<td>" << this->movies[ it ].get_likes() << "</td>\n";
		out << "			<td><a href =\"" << this->movies[ it ].get_trailer() << "\">Link</a></td>\n";
		out << "	</tr>\n";
	}

	out << "		</table>\n";
	out << "	</body>\n";
	out << "</html>\n";

	out.close();
}

void HTMLRepository::add_movie_to_watchlist(size_t movie_index) {
	Repository::add_movie_to_watchlist( movie_index );
	HTMLRepository::save_data();
}

void HTMLRepository::erase_movie_from_watchlist(size_t movie_index) {
	Repository::erase_movie_from_watchlist( movie_index );
	HTMLRepository::save_data();
}