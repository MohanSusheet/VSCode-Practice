#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void moveZeroesToEndBrute(vector<int> &arr)
{
    //Brute Force: using a temp array to store the non zero elements and appending
    //the number of zeroes in given array at the end of temp array.
    //T.C --> O(N)
    //S.C --> O(N)
    int n = arr.size();
    int countZeroes = 0;
    vector<int> temp;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)countZeroes++;
        else
        {
            temp.push_back(arr[i]);
        }
    }

    for(int i = 0; i < countZeroes; i++)
    {
        temp.push_back(0);
    }

    arr = temp;
}

void printArray(vector<int> &arr)
{
    for(auto it: arr)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}

void moveZeroesToEndOptimal(vector<int> &arr)
{
    //Optimal Approach: using 2 pointers i & j where j points to the first 0 
    //and i iterates the array. Swap the values at i and j whenever a[i] is non-zero
    //T.C -> O(N) & S.C --> O(1)
    int n = arr.size();

    int j = -1;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    if(j == -1)return;

    int i = j+1;

    while(i < n)
    {
        if(arr[i] != 0)
        {
            swap(arr[j++], arr[i++]);
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    vector<int> arr = {1,0,2,0,3,4,0,7,15,8,0};
    cout<<"Inital Array: ";
    printArray(arr);

    moveZeroesToEndBrute(arr);
    printArray(arr);

    arr = {1,0,2,0,3,4,0,7,15,8,0};

    moveZeroesToEndOptimal(arr);
    printArray(arr);
    
    return 0;
}