#include <iostream>
#include <vector>

using namespace std;

bool isArraySortedBrute(vector<int> &arr)
{
    int n = arr.size();

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[i])return false;
        }
    }
    return true;
}

bool isArraySortedOptimal(vector<int> &arr)
{
    int n = arr.size();

    for(int i = 0; i < n-1; i++)
    {
        if(arr[i] > arr[i+1])return false;
    }
    return true;
}

int main()
{
    vector<int> arr1 = {1,2,2,3,4,6,8,9,10};
    vector<int> arr2 = {1,2,2,3,4,6,8,9,1};

    cout<<isArraySortedBrute(arr1)<<"\n";
    cout<<isArraySortedOptimal(arr2);
    return 0;
}