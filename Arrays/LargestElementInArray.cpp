#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int largestElemetBrute(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    return arr[n-1];
}

int largestElemetOptimal(vector<int> &arr)
{
    int n = arr.size();
    int max_ele = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > max_ele)
        {
            max_ele = arr[i];
        }
    }

    return max_ele;
}

int main()
{
    vector<int> arr = {5, 1, 10, 3, 8, 4, 15, 7};

    int ans = largestElemetBrute(arr);
    cout<<"Maximum element is: "<<ans<<"\n";
    int ans1 = largestElemetOptimal(arr);
    cout<<"Maximum element is: "<<ans1;
    return 0;
}