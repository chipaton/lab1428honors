#include <iostream>

using namespace std;
int fact(int n);
int fib(int n);
int main()
{
    cout << "Input number for factorial." << endl;
   int in;
   cin >> in;
   int factor = fact(in);
   cout << factor << endl;
   cout <<"Input the number for fibonacci." << endl;
   int out;
   cin >> out;
   int fibon = fib(out);
   cout << fibon << endl;
    return 0;
}
int fact(int n)
{
    if(n == 0)
        return 1;
    return n * fact(n-1);
}

int fib(int n)
{
    if(n==0)
        return 0;
    if(n==1)
            return 1;
    return fib(n-1) + fib(n-2);
}
