#include "ui.h"

UI::UI(const Controller& controller) {
    this->controller = controller;
}

void UI::run() {
    int op;

    while(true) {
        std::cout<<"\nPress 0 to exit\nPress 1 to open the app in administrator mode.\nPress 2 to open the app in client mode.\nInsert your command:";
        std::cin >> op;
        if( op == 0 ) {
            std::cout << "\nGoodbye!\n";
            break;
        }
        if(op == 1) {
            run_admin_mode();
            continue;
        }
        if(op == 2) {
            run_client_mode();
            continue;
        }
        std::cout << "\nInvalid command!\n";
    }
}

void UI::run_admin_mode()
{
    while(true)
    {
        int op;

        std::cout << "\nPress 0 to exit\nPress 1 to add a movie\nPress 2 to erase a movie\nPress 3 to update a movie\nPress 4 to see all movies\nInsert your command:";
        std::cin >> op;

        if(op==0) {
            break;
        }
        if(op == 4) {
            for(auto it: controller.get_movies()) {
                std::cout << it.toString() << '\n';
            }
            continue;
        }
        if(op == 1) {
            std::string title, genre, trailer;
            int year, likes, duration;

            std::cin.get();
            std::cout << "\nTitle: ";
            getline(std::cin, title);
            std::cout << "Genre: ";
            getline(std::cin, genre);
            std::cout << "Trailer: ";
            getline(std::cin, trailer);
            std::cout << "Year: ";
            std::cin >> year;
            std::cout << "Likes: ";
            std::cin >> likes;
            std::cout << "Duration: ";
            std::cin >> duration;

            try{
                controller.add_movie(title, genre, trailer, year, likes, duration);
            }catch (const std::invalid_argument& err){
                std::cout << err.what() << '\n';
                continue;
            }
            std::cout << "Done!\n";
            continue;
        }
        if(op == 2) {
            std::string title, genre, trailer;
            int year, likes;

            std::cin.get();
            std::cout << "\nTitle: ";
            getline(std::cin, title);
            std::cout << "Genre: ";
            getline(std::cin, genre);
            std::cout << "Trailer: ";
            getline(std::cin, trailer);
            std::cout << "Year: ";
            std::cin >> year;

            try{
                controller.erase_movie(title, genre, trailer, year, likes, 0);
            }catch (const std::invalid_argument& err){
                std::cout << err.what() << '\n';
                continue;
            }

            std::cout << "Done!\n";
            continue;
        }
        if(op == 3) {
            std::string title, genre, trailer;
            std::string year, likes;

            std::cin.get();
            std::cout << "Enter the movie you want to modify\nTitle: ";
            getline(std::cin, title);
            std::cout << "Genre: ";
            getline(std::cin, genre);
            std::cout << "Trailer: ";
            getline(std::cin, trailer);
            std::cout << "Year: ";
            getline(std::cin, year);
            std::cout << "Likes: ";
            getline(std::cin, likes);

            std::string title1, genre1, trailer1;
            std::string year1, likes1; 

            std::cin.get();
            std::cout << "Leave the fields you don't want to modify empty!\nTitle: ";
            getline(std::cin, title1);
            std::cout << "Genre: ";
            getline(std::cin, genre1);
            std::cout << "Trailer: ";
            getline(std::cin, trailer1);
            std::cout << "Year: ";
            getline(std::cin, year1);
            std::cout << "Likes: ";
            getline(std::cin, likes1);

            try{
                controller.update_movie(title, genre, trailer, std::stoi(year), std::stoi(likes), title1, genre1, trailer1, year1, likes1);
            }catch (const std::invalid_argument& err) {
                std::cout << err.what() << '\n';
                continue;
            }
        }
    }
}

void UI::run_client_mode() {
    while(true) {
        int op;
        std::cout << "\nPress 0 to exit\nPress 1 to see all the movies by genre.\nPress 2 to see the watchlist\nPress 3 to rate a movie\nInsert your command:";
        std::cin >> op;
        if(op==0) {
            break;
        }
        if(op == 1) {
            std::string genre;

            std::cout << "Genre:";
            std::cin.get();
            getline(std::cin, genre);

            std::vector< Movie > movies = controller.get_movies_by_genre( genre );

            for(int i = 0;i < (int)movies.size() ;i++)
            {
                int y=2;
                while(y != 1)
                {
                    std::cout << '\n' << movies[i].toString();

                    std::cout << "\nPress 0 to exit\nPress 1 to go to the next movie\nPress 2 to see the trailer\nPress 3 to add to watchlist\nYour command:";
                    std::cin >> y;

                    if(y==1 || y==0) {
                        break;
                    }
                    if(y == 2) {
                        std::string link = std::string("opera ") + movies[ i ].get_trailer();
                        system( link.data() );
                    }
                    if(y==3) {
                        try{
                            controller.add_movie_to_watchlist( movies[ i ] );
                        }
                        catch (const std::invalid_argument& err) {
                            std::cout << err.what() << '\n';
                            continue;
                        }
                        break;
                    }
                }
                if(y == 0){
                    break;
                }
            }
        }
        if(op == 2) {
            std::cout << "\nYour Watchlist:\n";

            std::vector< Movie > movies = controller.get_movies();

            for(auto it: controller.get_watchlist()) {
                std::cout<<movies[ it ].toString();
            }
        }
        if(op == 3) {
            std::string title, genre;
            int year;

            std::cin.get();
            std::cout << "\nTitle: ";
            getline(std::cin, title);
            std::cout << "Genre: ";
            getline(std::cin, genre);
            std::cout << "Year: ";
            std::cin >> year;

            try{
                controller.rate_movie( Movie( title, genre, std::string(""), year, 0, 0 ) );
            }
            catch (const std::invalid_argument& err){
                std::cout << err.what() << '\n';
                continue;
            }
        }
    }
}

