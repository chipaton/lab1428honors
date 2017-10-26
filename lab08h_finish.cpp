#include <iostream>
#include <fstream>
using namespace std;
int jump(int first, int index, int place);
int cjump(int first, int index, int place, int comp1, int comp2);
int main()
{
	// Declare our variables
	const int OP_ADD = 0;
	const int OP_SUB = 1;
	const int OP_MUL = 2;
	const int OP_DIV = 3;
	const int OP_EXP = 4;
	const int OP_RED = 5;
	const int OP_WRT = 6;
	const int OP_STR = 7;
	const int OP_JMP = 8;
	const int OP_CJP = 9;
	int memory[256];
	int instruction[512][4]={0};
	int counter = 0;

	ifstream fin;
	fin.open("test.txt");

	while(!(fin.eof())&&counter < 512)
	{
		fin >> instruction[counter][0] >> instruction[counter][1] >> instruction[counter][2] >> instruction[counter][3];
		counter ++;
	}


	for(int i=0; i<counter; i++)
	{

		switch(instruction[i][0])
		{
			case OP_ADD:
				memory[instruction[i][1]] = memory[instruction[i][2]] + memory[instruction[i][3]];
				break;
			case OP_SUB:
				memory[instruction[i][1]] = memory[instruction[i][2]] - memory[instruction[i][3]];
				break;
			case OP_MUL:
				memory[instruction[i][1]] = memory[instruction[i][2]] * memory[instruction[i][3]];
				break;
			case OP_DIV:
				memory[instruction[i][1]] = memory[instruction[i][2]] / memory[instruction[i][3]];
				break;
			case OP_EXP:
				//IMPLEMENT HERE!
				break;
			case OP_RED:
				cout << "Enter a number:";
				cin >> memory[instruction[i][1]];
				break;
			case OP_WRT:
				cout << memory[instruction[i][1]] << endl;
				break;
			case OP_STR:
				memory[instruction[i][1]]=instruction[i][2];
				break;
			case OP_JMP:
				i = jump(i, instruction[i][1], counter) - 1;
				break;
			case OP_CJP:
				i = cjump(i, instruction[i][1], counter, instruction[i][2], instruction[i][3]) - 1;
				break;
		}
	}
	return 0;
}
int jump(int first, int  index, int place)
{
    if(first + index >= place)
        return first;
    if(first + index < 0)
        return first;
    return first + index;
}
int cjump(int first, int  index, int place, int comp1, int comp2)
{
    if(comp1 != comp2)
        return first;
    if(first + index >= place)
        return first;
    if(first + index < 0)
        return first;
    return first + index;
}


