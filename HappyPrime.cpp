#include <iostream>

using namespace std;
bool isPrime(int prime);
bool isHappy(int hap);
bool addToCycle(int ad);
bool CycleContains(int check);
void SelectionSort();
int nums[20];
int amt = 0;
int main()
{
    int num;
    cout << "Input the  number you want to check." << endl;
    cin >> num;
    if(isHappy(num) == true && isPrime(num) == true)
        cout << "The number is happy and prime." << endl;
    if(isHappy(num) == false && isPrime(num) == true)
        cout << "The number is sad and prime." << endl;
    if(isHappy(num) == true && isPrime(num) == false)
        cout << "The number is happy and not prime." << endl;
    if(isHappy(num) == false && isPrime(num) == false)
        cout << "The number is sad and not prime." << endl;


}
bool isPrime(int prime)
{
    int cnt = 0;
    if(prime == 1)
        return false;
    if(prime == 2)
        return true;
    if(prime%2 == 0)
        return false;
    for(int i = 1; i <= prime; i++)
    {
        if(prime%i == 0)
            cnt++;

    }
    if(cnt > 1)
            return false;
    else
        return true;

}
bool isHappy(int hap)
{
    int nums = hap;
   int digit;
   int sum = 0;
   while(nums > 0)
   {
       digit = (nums % 10);
       nums /= 10;
       sum+= digit * digit;
   }
   if( addToCycle(sum) == true)
    return isHappy(sum);
   else
    return false;


}
bool addToCycle(int ad)
{
    if(CycleContains(ad) == true)
        return false;

    nums[amt] = ad;
    amt++;
    SelectionSort();
    return true;

}
bool CycleContains(int check)
{
    for(int i = 0; i < amt; i++)
    {
        if(nums[i] == check)
            return true;
    }
    return false;
}
void SelectionSort()
{
    for(int i = 0; i < amt-1; i++)
    {
        int minn = i;
        for(int j = i+1; j < amt;j++)
        {
            if(nums[j] < nums[minn])
                minn = j;
        }
        if( minn != i)
        {
            int temp = nums[minn];
            nums[minn] = nums[i];
            nums[i] = temp;
        }
    }
}
