#include <iostream>

using namespace std;
struct mp3{
    string title, name, genre;
    int track;
    bool favorite;



};
int main()
{
    mp3 music[100];
    bool cont = true;
    int songtracker = 0;
    while(cont == true){
    cout << "Welcome to the MP3 Manager!" << endl;
    cout << "1) New Song." << endl << "2) Delete Song." << endl << "3) Display All Songs." << endl << "4) Edit Song." << endl << "5) Print Favorites." << "6) Exit." <<  endl << "Enter Choice: ";
    int choice;
    cin >> choice;
    if(choice == 1)
    {

        cout << endl << "Enter song title. ";
         cin >> music[songtracker].title;
         cout << endl << "Enter genre name. ";
         cin >> music[songtracker].genre;
         cout << endl << "Enter filename. ";
         cin >> music[songtracker].name;
         cout << endl << "Enter 1 if song is favorite, 0 if not. ";
         int fav;
         cin >> fav;
         if(fav == 0)
            music[songtracker].favorite = false;
         else
            music[songtracker].favorite = true;
        songtracker++;

    }
    if(choice == 2)
    {
        cout << "Enter track number to be deleted." << endl;
        int tracknumber;
        cin >> tracknumber;
        music[tracknumber].title = "";
        music[tracknumber].name = "";
        music[tracknumber].genre = "";
        music[tracknumber].track = 0;
        music[tracknumber].favorite = false;
        cout << "Completed." << endl;
    }
    if(choice == 3)
    {
        for(int i = 0; i < songtracker; i++)
        {
            cout << music[i].title << endl;
        }
    }
    if(choice == 4)
    {
        int cho;
        cout << "Enter the track number to be edited." << endl;
        cin >> cho;
        cout << endl << "Enter song title. ";
         cin >> music[cho].title;
         cout << endl << "Enter genre name. ";
         cin >> music[cho].genre;
         cout << endl << "Enter filename. ";
         cin >> music[cho].name;
         cout << endl << "Enter 1 if song is favorite, 0 if not. ";
         int fav;
         cin >> fav;
         if(fav == 0)
            music[cho].favorite = false;
         else
            music[cho].favorite = true;

    }
    if(choice == 5)
    {
        for(int i = 0; i < 100; i++)
        {
            if(music[i].favorite == true)
                cout << music[i].title;
        }
    }
    if(choice == 6)
    {
        cout << "Exiting.";
        cont = false;
    }

    }
    return 0;
}
