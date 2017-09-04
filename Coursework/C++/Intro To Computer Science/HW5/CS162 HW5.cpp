#include "list.h"

int main()
{
    list place;
    int choice = 0;

    place.welcome();

    do
    {
        place.space(100);
        choice = place.interface(); //Calls interface function to display user interface

        place.space(100);           //Creates a clean page after every command

        switch (choice)             //Switch statement with 5 commands
        {
            case 1:
            {
                place.add();    //Add game to gameArray
            }break;

            case 2:
            {
                place.move();   //Find a game in collection
            }break;

            case 3:
            {
                place.display(); //Display full info of all games
            }break;

            default:break;
        }
    }while (choice!=4);
    return 0;
}
