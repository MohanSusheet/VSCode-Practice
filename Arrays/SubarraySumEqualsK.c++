#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int subarraySumEqualsKBrute(vector<int> &arr, int k)
{
    int n = arr.size(), ans = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int sum = 0;
            for(int l = i; l <= j; l++)
            {
                sum += arr[l];
            }
            if(sum == k)ans++;
        }
    }
    return ans;
}

int subarraySumEqualsKBetter(vector<int> &arr, int k)
{
    int n = arr.size(), ans = 0;

    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += arr[j];
            if(sum == k)
            {
                ans++;
            }
        }
    }
    return ans;
}

int subarraySumEqualsKOptimal(vector<int>&arr, int k)
{
    int n = arr.size(), ans = 0, prefixSum = 0;
    map<int, int> mp;
    mp[0] = 1;

    for(int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        ans += mp[prefixSum - k];
        mp[prefixSum]++;
    }
    return ans;
}

int main()
{
    vector<int> arr = {1,4,5,3,-4,8,1,9,-1,10,5,1,7};
    int k = 8;
    //T.C -> O(n^3), S.C -> O(1)
    cout << "Subarrays with sum equal to "<<k<<" are : "<<subarraySumEqualsKBrute(arr, k)<<"\n";
    
    //T.C -> O(n^2), S.C -> O(1)
    cout << "Subarrays with sum equal to "<<k<<" are : "<<subarraySumEqualsKBetter(arr, k)<<"\n";

    //T.C -> O(n), S.C -> O(n)
    cout << "Subarrays with sum equal to "<<k<<" are : "<<subarraySumEqualsKOptimal(arr, k)<<"\n";
    return 0;
}