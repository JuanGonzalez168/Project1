#include <iostream>
#include <iomanip>


void displayMenu()
{
    std::cout << "\n\n"
        << std::setfill('=') << std::setw(30) << "APPLE MUSIC"
        << std::setfill('=') << std::setw(20) << "\n\n";

    std::cout << "Option 1: Display all songs in list.\n"
        << "Option 2: Add songs to list.\n"
        << "Option 3: Display all songs for an artist.\n"
        << "Option 4: Remove all songs below a certain number of likes.\n"
        << "Option 5: Edit number of likes for a song.\n"
        << "Option 6: Quit Apple Music\n"
        << "\n\n";
}

void displayMenuOptionTwo()
{
    std::cout << "\n\n"
        << std::setfill('=') << std::setw(30) << "APPLE MUSIC"
        << std::setfill('=') << std::setw(20) << "\n\n";

    std::cout << "\nOption 1: Load Songs from a file."
        << "\nOption 2: Enter each song individually"
        << "\nOPtion 3: Quit to main menu\n\n";
}