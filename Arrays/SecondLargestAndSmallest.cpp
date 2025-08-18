#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

vector<int> secondLargestAndSmallestBrute(vector<int> &arr)
{
    int n = arr.size();
    if(n <= 1) //size should be at least 2 (so we can have largest, second largest and smallest, second smallest)
    {
        return {-1, -1, -1, -1};
    }
    sort(arr.begin(), arr.end());

    return {arr[0], arr[1], arr[n-1], arr[n-2]};
}

vector<int> secondLargestAndSmallestBetter(vector<int> &arr)
{
    int n = arr.size();
    if(n <= 1)
    {
        return {-1, -1, -1, -1};
    }

    int smallest = INT_MAX, second_smallest = INT_MAX;
    int largest = INT_MIN, second_largest = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        smallest = min(arr[i], smallest);
        largest = max(arr[i], largest);
    }

    for(int i = 0; i < n; i++)
    {
        if(arr[i] < second_smallest && arr[i] != smallest)
        {
            second_smallest = arr[i];
        }
        if(arr[i] > second_largest && arr[i] != largest)
        {
            second_largest = arr[i];
        }
    }

    return {smallest, second_smallest, largest, second_largest};
}

vector<int> secondLargestAndSmallestOptimal(vector<int> &arr)
{
    int n = arr.size();
    if(n <= 1)return {-1, -1, -1, -1};

    int smallest = INT_MAX, second_smallest = INT_MAX;
    int largest = INT_MIN, second_largest = INT_MIN;

    for(int i=0; i < n; i++)
    {
        if(arr[i] < smallest)
        {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < second_smallest && arr[i] != smallest)
        {
            second_smallest = arr[i];
        }
        else if(arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if(arr[i] > largest && arr[i] != largest)
        {
            second_largest = arr[i];
        }
    }
    return {smallest, second_smallest, largest, second_largest};
}

int main()
{
    vector<int> arr = {9, 4, 7, 1, 13, 15, 17, 8, 2};

    vector<int> ans1 = secondLargestAndSmallestBrute(arr);
    cout<<"Smalleset is: "<<ans1[0]<<". Second smallest is:"<<ans1[1]<<". Largest is:"
    <<ans1[2]<<". Second largest is:"<<ans1[3]<<"\n";

    vector<int> ans2 = secondLargestAndSmallestBetter(arr);
    cout<<"Smalleset is: "<<ans2[0]<<". Second smallest is:"<<ans2[1]<<". Largest is:"
    <<ans2[2]<<". Second largest is:"<<ans2[3]<<"\n";

    vector<int> ans3 = secondLargestAndSmallestOptimal(arr);
    cout<<"Smalleset is: "<<ans3[0]<<". Second smallest is:"<<ans3[1]<<". Largest is:"
    <<ans3[2]<<". Second largest is:"<<ans3[3]<<"\n";
    return 0;
}