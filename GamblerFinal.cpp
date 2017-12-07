#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
void betFunc(int myMoney, int &bet);
void getRolls(int &compDie1, int &userDie1);
void results(int compDie1, int userDie1, int &myMoney, int betAmount);


int main()
{
    bool cont = true;
    cout << "Gambling is an addiction..." << endl;
    int myMoney = 1000;
    int compDie1 = 0;
    int userDie1 = 0;
    int bet = 0;

    while(cont == true)
    {


    betFunc(myMoney, bet);
    getRolls(compDie1, userDie1);
    results(compDie1, userDie1, myMoney, bet);
    cout << "Would you like to continue? (Y/N)" << endl;
    char choice;
    cin >> choice;
    choice = toupper(choice);
    if(choice == 'N')
        cont = false;
    if(myMoney == 0)
    {
        cout << "You have no more money.";
        cont = false;
    }

    }

    return 0;
}

void betFunc(int myMoney, int &bet)
{
    cout << "You currently have $" << myMoney << endl;
    cout << "How much do you bet?" << endl;
    cin >> bet;
    while(bet > myMoney)
    {
        cout << "You do not have that much money. Try again." << endl;
        cin >> bet;
    }
}
void getRolls(int &compDie1, int &userDie1)
{
    srand(time(NULL));
    compDie1 = rand() % 6 + 1;
    userDie1 = rand() % 6 + 1;
}
void results(int compDie1, int userDie1, int &myMoney, int bet)
{
    cout << "You rolled a " << userDie1 << endl;
    cout << "Your opponent rolled a " << compDie1 << endl;
    if(compDie1 > userDie1)
    {
        cout << "You lost $" << bet << endl;
        myMoney -= bet;
    }
    if(compDie1 < userDie1)
    {
        cout << "You gain $"<< bet << endl;
        myMoney += bet;
    }
    if(compDie1 == userDie1)
    {
        cout << "There was a draw." << endl;

    }
}
