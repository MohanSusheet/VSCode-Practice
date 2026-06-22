#include<iostream>
#include<vector>
using namespace std;


void getSum(int i, int n, int sum)
{
    if(i > n)
    {
        cout<<sum;
        return;
    }
    sum += i;
    getSum(i+1, n, sum);
}

int calculateSum(int n)
{
    if(n == 1)return 1;
    return n + calculateSum(n-1);
}

//parameterized recursion
void printSumFrom1toN(int n)
{
    int sum = 0;
    //calling parameterized function - carry the running total
    getSum(1, n, sum);

    //calling function with a return value i.e. function recursion - Break the problem into a sub-problem and add the current value to the result of that sub-problem.
    cout<<"\nFunctional Rec result: "<<calculateSum(n);
}

void reverseArr(int left, int right, vector<int>&arr)
{
    if(left > right)return;

    swap(arr[left], arr[right]);
    reverseArr(left+1, right-1, arr);
}

bool isPalindrome(int left, int right, string s)
{
    if(left > right)return true;

    return s[left] == s[right] && isPalindrome(left + 1, right - 1, s);
}

int main()
{
    // int n;
    // cin>>n;

    // printSumFrom1toN(n);

    // problem 1 : use Functional recursion to reverse an array
    // vector<int> arr = {1,2,3,4,5,6};
    // int n = 6;
    // cout<<"Before reverse\n";
    // for(auto it: arr)cout<<it<<" ";
    // reverseArr(0, n-1, arr);
    // cout<<"\nAfter reverse\n";
    // for(auto it: arr)cout<<it<<" ";

    //problem 2 : check whether the string a palindrome or not
    string s = "madams";
    cout<<isPalindrome(0, s.size() - 1, s);
    return 0;
}