#include <iostream>
#include <vector>
#include <cstring>

class Movie{
    public:
        std::string title;
        std::string director;
        int releaseYear;
        std::string genre;
        bool isRented;

        Movie(std::string x, std::string y, int z, std::string j){
            title = x;
            director = y;
            releaseYear = z;
            genre = j;
            isRented = false;
        }
    
        void Display() const{
            std::cout << "Title: " << title << "\n";
            std::cout << "Director: " << director << "\n";
            std::cout << "Release Year: " << releaseYear << "\n"; 
            std::cout << "Genre: " << genre << "\n";
            std::cout << "Is Rented: " << isRented << "\n";
        }
};

class MovieRentalSystem{
    private:
        std::vector<Movie> movies;

    public:

        void AddMovie(){
            std::string title, director, genre;
            int releaseYear;

            std::cout << "Adding Movie\n";
            std::cout << "Title: ";
            std::cin >> title;

            std::cout << "Director: ";
            std::cin >> director;

            std::cout << "Release Year: ";
            std::cin >> releaseYear;

            std::cout << "Genre: ";
            std::cin >> genre;

            Movie newMovie(title, director, releaseYear, genre);
            movies.push_back(newMovie);
        }

        void DisplayMovies(){
            if (movies.empty()){
                std::cout << "There iare no movies";
            }else{
                for(const auto& movie : movies){
                    movie.Display();
                    std::cout << "\n~-~NEXT~-~\n\n";
                }
            }
            
        }

        void SearchMovie(){
            std::string searchMovieTitle;

            std::cout << "Enter the search title: ";
            std::cin >> searchMovieTitle;

            if(movies.empty()){
                std::cout << "There iare no movies";
            }else{
                for (const auto& movie : movies){
                    if(movie.title == searchMovieTitle){
                        movie.Display();
                    }
                }
                
            }
        }

        void RemoveMovie(){
            std::string searchMovieTitle;

            std::cout << "Enter the search title to remove: ";
            std::cin >> searchMovieTitle;

            for (int i = 0; i < movies.size(); i++){
                if(movies[i].title == searchMovieTitle){
                    movies.erase(movies.begin() + i);
                    std::cout << "Movie \"" << searchMovieTitle << "\" has been removed.\n";
                    return;
                }
            }
            
            std::cout << "Movie \"" << searchMovieTitle << "\" not found.\n";

        }

        void UpdateRentalStatus(){
            std::string searchMovieTitle;

            std::cout << "Enter the search title to remove: ";
            std::cin >> searchMovieTitle;

            for (int i = 0; i < movies.size(); i++){
                if (movies[i].title == searchMovieTitle){
                    char Choise;

                    if (movies[i].isRented ==false){
                        std::cout << "The movie is not ranted\n";
                        
                        std::cout << "Would you like to rent the movie (Y/N): ";
                        std::cin >> Choise;

                        if(Choise == 'Y' || Choise == 'y'){
                            std::cout << "Great, have a nice day\n";
                            movies[i].isRented == true;
                        }else if(Choise == 'N' || Choise == 'n'){
                            std::cout << "OK!\n";
                        }
                        
                        return;
                    }else{
                        std::cout << "The movie is ranted\n";

                        std::cout << "Are you going to return the movie (Y/N): ";
                        std::cin >> Choise;

                        if(Choise == 'Y' || Choise == 'y'){
                            std::cout << "Great, have a nice day\n";
                            movies[i].isRented == false;
                        }else if(Choise == 'N' || Choise == 'n'){
                            std::cout << "OK!\n";
                        }

                        return;
                    } 
                }
            }
        }
};


int main() {
    MovieRentalSystem system;
    int choice;

    do {
        std::cout << "\nMovie Rental System Menu:\n";
        std::cout << "1. Add Movie\n";
        std::cout << "2. Display Movies\n";
        std::cout << "3. Search Movie\n";
        std::cout << "4. Remove Movie\n";
        std::cout << "5. Update Rental Status\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: system.AddMovie(); break;
            case 2: system.DisplayMovies(); break;
            case 3: system.SearchMovie(); break;
            case 4: system.RemoveMovie(); break;
            case 5: system.UpdateRentalStatus(); break;
            case 6: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}