#include<iostream>
using namespace std;

void printName5Times(string name, int n)
{
    if(n == 0)return;
    cout<<name<<" ";
    printName5Times(name, n-1);
}

void printLinearlyFrom1ToN(int i, int n)
{
    if(i > n)return;
    cout<<i<<" ";
    printLinearlyFrom1ToN(i+1, n);
}

void printFromNTo1(int n)
{
    if(n == 0)return;
    cout<<n<<" ";
    printFromNTo1(n-1);
}

void backtracking1toN(int n)
{
    if(n == 0)return;
    backtracking1toN(n-1);
    cout<<n<<" ";
}

void backtrackingNto1(int n)
{
    if(n == 0)return;
    cout<<n<<" ";
    backtracking1toN(n-1);
}

int main()
{
    //Problem 1
    printName5Times("Susheet", 5);
    
    int n;
    cout<<"Please enter the value of n: ";
    cin>>n;
    //Proble 2
    // printLinearlyFrom1ToN(1, n);
    // cout<<endl;
    
    // //Problem 3
    // printFromNTo1(n);
    
    cout<<endl;
    //problem 4
    backtracking1toN(n);

    cout<<endl;
    //Problem 5
    backtrackingNto1(n);
    return 0;
}