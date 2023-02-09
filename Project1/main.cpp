#include "list.h"
#include "song.h"
#include <fstream>
#include <iomanip>
#include <limits>
#include <sstream>

void displayMenu();
void displayMenuOptionTwo();

void addSongsToList(List &list);
void loadSongsFromFile(List &list); 
void loadSongsIndividually(List &list);
void displaySongsInOrder(List &list);
void editNumberOfLikes(List &list);
void removeSongsLikes(List &list);

int  checkValidUserInput();
void clearStreamBuffer();

const int MAX_CHAR = 101;



int main(int argc, char** argv)
{
   
    int userOption;
    List list;

    do
    {
       displayMenu();

       std::cout << "Enter option between 1-6: ";
       userOption = checkValidUserInput();

       switch (userOption)
       {
            case 1:

                if(list.isEmpty())
                {
                    std::cout << "\nList is Empty!\n";
                }
                list.printList();
                break;

            case 2:

                addSongsToList(list); 
                break;

            case 3:

                displaySongsInOrder(list);
                break;

            case 4:

                removeSongsLikes(list);
                break;

            case 5:
                
                editNumberOfLikes(list);
                break;

            case 6:

                std::cout << "\nShuting Down....\n";
                break;

            default:
               std::cout << "\nError... not a number between (1-6).\n";
       } 
         
    }while(userOption != 6);
     
    std::cout << "\nAPPLE MUSIC HAS ENDED\n";
};


void removeSongsLikes(List& list)
{
    int number;
    std::cout << "\nEnter the number likes to remove songs below: ";
    std::cin >> number;
    clearStreamBuffer();

    
    if (!list.removeSongsBelowNumberOfLikes(number))
    {
        std::cout << "\nError no songs where removed!\n";
    }
    else
    {
        std::cout << "\nSuccesfully removed songs below " << number << " likes!\n";
    }
}


void addSongsToList(List &list)
{
    int userOption;
    do
    {
        displayMenuOptionTwo();
        userOption = checkValidUserInput();

        switch(userOption)
        {

            case 1:
                loadSongsFromFile(list); 
                break;

            case 2:
                loadSongsIndividually(list);
                break; 

            case 3:

                std::cout << "\nReturning to Main Menu...\n";
                break;

            default:
                std::cout << "\nError... not a number between (1-3)\n";
        }

    }while(userOption != 3);

}


int checkValidUserInput()
{
    int userInput = -1;
    bool isValidInput = false;
    while(!isValidInput)
    {
        std::cout << "\nEnter Here: ";
        std::cin >> userInput;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "\nERROR, TRY AGAIN\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(std::cin.gcount() > 1)
        {
            std::cout << "\nERROR, TRY AGAIN\n";
            continue;
        }
        isValidInput = true;
    }
    return userInput;
}


void loadSongsFromFile(List &list)
{
    std::fstream infile;
    char datafile[MAX_CHAR];

    std::cout << "\nEnter a file name: ";
    std::cin >> datafile;
    clearStreamBuffer();

    infile.open(datafile);

    if(!infile)
    {
        std::cerr << "\nFailed to open " << datafile << " for reading!" << std::endl;
        exit(1);
    }

    char tempArtist[MAX_CHAR];
    char tempTitle[MAX_CHAR];
    float tempLength = 0;
    int tempLikes = 0;
    Song tempSong;

    while(!infile.eof())
    { 
        infile.get(tempArtist,MAX_CHAR,';');
        infile.get();
        infile.get(tempTitle,MAX_CHAR,';');
        infile.get();
        infile >> tempLength;
        infile.get();
        infile >> tempLikes;
        infile.ignore(MAX_CHAR,'\n');

        tempSong.setArtist(tempArtist);
        tempSong.setTitle(tempTitle);
        tempSong.setLength(tempLength);
        tempSong.setLikes(tempLikes);
        list.add(tempSong);

        infile.peek();
    }

    infile.close(); 
    std::cout << "\nUpdated list from file: " << datafile << "\n";;
}


void loadSongsIndividually(List &list)
{
    char tempArtist[MAX_CHAR];
    char tempTitle[MAX_CHAR];
    float tempLength = 0;
    int tempLikes = 0;

    std::cout << "\nEnter Artist Name: ";
    std::cin.get(tempArtist,MAX_CHAR); 

    clearStreamBuffer();
    
    std::cout  << "Enter the title of song: ";
    std::cin.get(tempTitle,MAX_CHAR); 
    clearStreamBuffer();

    std::cout << "Enter the length of the song: ";
    std::cin >> tempLength;

    std::cout << "Enter the number of likes for the song: ";
    std::cin >> tempLikes;

    Song tempSong(tempArtist,tempTitle,tempLength,tempLikes);
    list.add(tempSong);
    std::cout << "\nSuccesfully added " << tempArtist << " to the list!\n";
}


void editNumberOfLikes(List &list)
{
    char tempArtist[MAX_CHAR];
    char tempTitle[MAX_CHAR];
    int likesToChange = 0; 

    std::cout << "\nEnter artist name: ";
    std::cin.get(tempArtist,MAX_CHAR);
    clearStreamBuffer();

    std::cout << "Enter song name: ";
    std::cin.get(tempTitle,MAX_CHAR);
    clearStreamBuffer();
    
    std::cout <<"Enter number of likes: ";
    std::cin >> likesToChange;
    clearStreamBuffer();

    if(list.editSongLikes(tempArtist,tempTitle,likesToChange))
    {
        std::cout << "Song has been edited!\n";
    }
    else {std::cout << "Song not found!\n";}
}


void displaySongsInOrder(List &list)
{
   if(list.isEmpty())
   {
        std::cout << "\nList is Empty!\n";
   }
   else
   {
       std::cout << "Enter artist name to display: ";

        int const MAX_CHAR = 101;
        char tempArtist[MAX_CHAR];
        std::cin.get(tempArtist,MAX_CHAR);
        clearStreamBuffer();
        if(!list.displayArtistInOrderPopularity(tempArtist))
        {
            std::cout << "\nArtist Not Found!\n";
        }

   }
}


void clearStreamBuffer()
{
    std::cin.clear();
    std::cin.ignore(MAX_CHAR,'\n');
}

