#include "UI.h"

UI::UI(const Controller& cont) : controller(cont)
{
}

void UI::Run()
{
    int x;
    while(true)
    {
        std::cout<<"\nPress 0 to exit\nPress 1 to open the app in administrator mode.\nPress 2 to open the app in client mode.\nInsert your command:";
        std::cin>>x;
        if(x==0)
        {
            std::cout<<"\nGoodbye!\n";
            break;
        }
        if(x==1)
        {
            RunAdminMode();
            continue;
        }
        if(x==2)
        {
            RunClientMode();
            continue;
        }
        std::cout<<"\nInvalid command!\n";
    }
}

void UI::RunAdminMode()
{
    while(true)
    {
        int x;
        std::cout<<"\nPress 0 to exit\nPress 1 to add a movie\nPress 2 to erase a movie\nPress 3 to update a movie\nPress 4 to see all movies\nInsert your command:";
        std::cin>>x;
        if(x==0)
        {
            return;
        }
        if(x==4)
        {
            vector< Movie > v(controller.GetMovies());
            for(size_t i = 0; i < v.size(); i++)
            {
                std::cout<<v[i].toString()<<'\n';
            }
            continue;
        }
        if(x==1)
        {
            std::string title,genre,trailer;
            int year,likes;
            std::cin.get();
            std::cout<<"\nTitle: ";
            getline(std::cin,title);
            std::cout<<"Genre: ";
            getline(std::cin,genre);
            std::cout<<"Trailer: ";
            getline(std::cin,trailer);
            std::cout<<"Year: ";
            std::cin>>year;
            std::cout<<"Likes: ";
            std::cin>>likes;

            try{
                controller.AddMovie(title,genre,trailer,year,likes);
            }catch (const std::invalid_argument& err){
                std::cout<<err.what()<<'\n';
                continue;
            }
            std::cout<<"Done!\n";
            continue;
        }
        if(x==2)
        {
            std::string title,genre,trailer;
            int year,likes=0;
            std::cin.get();
            std::cout<<"\nTitle: ";
            getline(std::cin,title);
            std::cout<<"Genre: ";
            getline(std::cin,genre);
            std::cout<<"Trailer: ";
            getline(std::cin,trailer);
            std::cout<<"Year: ";
            std::cin>>year;

            try{
                controller.EraseMovie(title,genre,trailer,year,likes);
            }catch (const std::invalid_argument& err){
                std::cout<<err.what()<<'\n';
                continue;
            }

            std::cout<<"Done!\n";
            continue;
        }
        if(x==3)
        {
            std::string title,genre,trailer;
            std::string year,likes;
            std::cin.get();
            std::cout<<"Enter the movie you want to modify\nTitle: ";
            getline(std::cin,title);
            std::cout<<"Genre: ";
            getline(std::cin,genre);
            std::cout<<"Trailer: ";
            getline(std::cin,trailer);
            std::cout<<"Year: ";
            getline(std::cin,year);
            std::cout<<"Likes: ";
            getline(std::cin,likes);

            std::string title1,genre1,trailer1;
            std::string year1,likes1;

            //std::cin.get();
            std::cout<<"Leave the fields you don't want to modify empty!\nTitle: ";
            getline(std::cin,title1);
            std::cout<<"Genre: ";
            getline(std::cin,genre1);
            std::cout<<"Trailer: ";
            getline(std::cin,trailer1);
            std::cout<<"Year: ";
            getline(std::cin,year1);
            std::cout<<"Likes: ";
            getline(std::cin,likes1);

            try{
                controller.UpdateMovie(title,genre,trailer,std::stoi(year),std::stoi(likes),title1,genre1,trailer1,year1,likes1);
            }catch (const std::invalid_argument& err){
                std::cout<<err.what()<<'\n';
                continue;
            }
        }
    }
}

void UI::RunClientMode()
{
    while(true)
    {
        int x;
        std::cout<<"\nPress 0 to exit\nPress 1 to see all the movies by genre.\nPress 2 to see the watchlist\nPress 3 to rate a movie\nInsert your command:";
        std::cin>>x;
        if(x==0)
        {
            break;
        }
        if(x==1)
        {
            std::string genre;
            std::cout<<"Genre:";
            std::cin.get();
            getline(std::cin,genre);
            vector< Movie > v(controller.GetMoviesByGenre(genre));
            for(int i=0;i<(int)v.size();i++)
            {
                int y=2;
                while(y!=1)
                {
                    std::cout<<'\n'<<v[i].toString();
                    std::cout<<"\nPress 0 to exit\nPress 1 to go to the next movie\nPress 2 to see the trailer\nPress 3 to add to watchlist\nYour command:";
                    std::cin>>y;
                    if(y==1 || y==0)
                    {
                        break;
                    }
                    if(y==2)
                    {
                        std::string link=std::string("opera ")+v[i].getTrailer();
                        system(link.data());
                    }
                    if(y==3)
                    {
                        try{
                            controller.AddMovieToWatchlist(v[i]);
                        }
                        catch (const std::invalid_argument& err){
                            std::cout<<err.what()<<'\n';
                            continue;
                        }
                        break;
                    }

                }
                if(y==0)
                {
                    break;
                }
            }
        }
        if(x==2)
        {
            std::cout<<"\nYour Watchlist:\n";
            vector< Movie > movies(controller.GetMovies());
            vector<int> watchlist(controller.GetWatchlist());
            for(size_t i=0;i<watchlist.size();i++)
            {
                std::cout<<movies[ watchlist[i] ].toString();
            }
        }
        if(x==3)
        {
            std::string title,genre;
            int year;
            std::cin.get();
            std::cout<<"\nTitle: ";
            getline(std::cin,title);
            std::cout<<"Genre: ";
            getline(std::cin,genre);
            /*std::cout<<"Trailer: ";
            getline(std::cin,trailer);*/
            std::cout<<"Year: ";
            std::cin>>year;

            try{
                controller.RateMovie( Movie(title,genre,std::string(""),year,0) );
            }
            catch (const std::invalid_argument& err){
                std::cout<<err.what()<<'\n';
                continue;
            }
        }
    }
}
