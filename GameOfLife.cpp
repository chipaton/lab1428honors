#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int calc_neighbor(char grid[10][10], int a, int b);
int main()
{
	//NUMBER OF ROWS AND COLUMNS
	const int ROWS = 10;
	const int COLS = 10;
	char life[ROWS][COLS];

	//RANDOM NUMBER GENERATOR TO CREATE INITIAL GENERATION
	srand (time(NULL));
	int cell;

	for(int r=0; r<ROWS; r++)
	{
		for(int c =0; c<COLS;c++)
		{
			cell = rand() % 7;
			if(cell >= 5)
			{
				life[r][c] = '*';
			}
			else
			{
				life[r][c]=' ';
			}
		}
	}
	int iterations;
	cout << "How many iterations do you want?" << endl;
	cin >> iterations;
	for(int i = 0; i < iterations; i++)
    {
        cout << "Generation #" << i+1 << endl;
       char copy[10][10];

        for(int r=0; r<ROWS; r++)
        {
		for(int c =0; c<COLS;c++)
		{
			copy[r][c] = life[r][c];
		}

        }
        for(int r=0; r<ROWS; r++)
        {
		for(int c =0; c<COLS;c++)
		{
			if(calc_neighbor(copy, r, c) < 2)
                life[r][c] = ' ';
            if(calc_neighbor(copy, r , c) == 3 && copy[r][c] == ' ')
                life[r][c] = '*';
            if(calc_neighbor(copy, r , c) > 3)
                life[r][c] = ' ';
		}

        }
        for(int r=0; r<ROWS; r++)
	{
		for(int c =0; c<COLS;c++)
		{
			cout << life[r][c];
		}
		cout << endl;
	}
    }


	return 0;

}
int calc_neighbor(char grid[10][10] , int a, int b)
{
    int total = 0;
    if(a > 0 && grid[a+1][b] == '*')
        total++;
    if(b > 0 && grid[a][b+1] == '*')
        total++;
    if(a < 10 && grid[a-1][b] == '*')
        total++;
    if( b < 10 && grid[a][b-1] == '*')
        total++;
    if(b > 0 && a > 0 && grid[a+1][b+1] == '*')
        total++;
    if(a > 0 && b < 10 && grid[a+1][b-1] == '*')
        total++;
    if(b > 0 && a < 10 && grid[a-1][b+1] == '*')
        total++;
    if(a < 10 && b < 10 && grid[a-1][b-1] == '*')
        total++;

    return total;
}
