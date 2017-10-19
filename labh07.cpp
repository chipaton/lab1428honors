#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    int num_instructions;
    const int OP_ADD = 0;
    const int OP_SUB = 1;
    const int OP_MUL = 2;
    const int OP_DIV = 3;
    const int OP_MOD = 4;
    const int OP_EXP = 5;
    const int OP_READ = 6;
    const int OP_WRITE = 7;
    int mem[256] = {4, 23, 10, 5};
    int inst[256] = {0};
    int data0[256] = {0};
    int data1[256] = {0};
    int data2[256] = {0};
    cout << "WE have the array memory[256] that currently has the values {4, 23, 10, 5}" << endl;
   // cout << "Input the amounts of instructions you want to perform." << endl;
   // cin >> num_instructions;
   ifstream fin;
   fin.open("test.txt");
   if(!fin)
   {
       cout << "Could not open file.";
       return -1;
   }
   fin >> num_instructions;
    for(int i = 0; i < num_instructions; i++)
    {
        int op;
        cout << "Input the number for the operation you wish to perform, where you want to write it, and the two values." << endl;
        fin >> inst[i] >> data0[i] >> data1[i] >> data2[i];
        if(data0[i] > 256)
        {
            cout << "I said there is a size of 256, idiot.";
            return -1;
        }
        if(inst[i] > 7)
        {
            cout << "There are only operations from 0-7, idiot.";
            return -1;
        }
        switch(inst[i])
    {
       case OP_ADD : mem[data0[i]] = (mem[data1[i]] + mem[data2[i]]);
                    break;
       case OP_SUB : mem[data0[i]] = (mem[data1[i]] - mem[data2[i]]);
                    break;
       case OP_MUL : mem[data0[i]] = (mem[data1[i]] * mem[data2[i]]);
                    break;
      case OP_DIV : mem[data0[i]] = (mem[data1[i]] / mem[data2[i]]);
                    break;
       case OP_MOD : mem[data0[i]] = (mem[data1[i]] % mem[data2[i]]);
                    break;
       case OP_EXP : mem[data0[i]] = pow(mem[data1[i]], mem[data2[i]]);
                    break;
       case OP_READ : cout << "What value do you want to input?" << endl;
                        fin >> mem[data0[i]];
                        break;
       case OP_WRITE : cout << mem[data0[i]] << endl;
    }
        cout << mem[data0[i]];

    }



    return 0;
}
