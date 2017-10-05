#include <iostream>

using namespace std;

int main()
{


    double tip, tipamt, cost;
    cout << "Input the cost of your meal followed by the percent amount tip you want to leave." << endl;
    cin >> cost >> tipamt;
    if(cost < 0)
    {
        cout << "This cost is a negative number try again.";
        cin >> cost;
        if(cost < 0)
        {
            cout << "Still wrong.";
            return -1;
        }
    }
    if(tipamt < 0)
     {
        cout << "This tip is a negative number try again.";
        cin >> tipamt;
        if(tipamt < 0)
        {
            cout << "Still wrong.";
            return -1;
        }
    }
    tip = cost * (tipamt/100);
    cout << "The tip would be $" << tip << endl;;
    return tip;
}
