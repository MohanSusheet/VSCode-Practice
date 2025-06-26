#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>&arr)
{
    int n = arr.size();
    int breakPt = -1;

    for(int i = n-1; i > 0; i--)
    {
        if(arr[i-1] < arr[i])
        {
            breakPt = i-1;
        }
    }
    if(breakPt == -1)
    {
        reverse(arr.begin(), arr.end());
        return;
    }

    for(int i = n-1; i > 0; i--)
    {
        if(arr[i] > arr[breakPt])
        {
            swap(arr[i], arr[breakPt]);
        }

        reverse(arr.begin() + breakPt + 1, arr.end());
    }
}

void printArr(vector<int>&arr)
{
    for(auto it: arr)cout<<it<<" ";
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    nextPermutation(arr);
    printArr(arr);

    return 0;
}