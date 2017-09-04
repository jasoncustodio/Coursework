/*
    Program: Blogs
    Author:  Jason Custodio
    Class:   CS163
    Date:    01/23/2014
    Description: Easier way to provide clean output.
*/

class menu
{
    public: menu();     //constructor - initializes data members
                        //destructor - deallocate all dynamic memory

            void check (); //Checkpoint pause
            void welcome   (); //Welcome user
            int  interface (); //Display user interface
            void space (int); //Provides clean output buffer
};
