#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

int LargestSubarrayWith0SumBrute(vector<int>&arr)
{
    //Brute Approach: generating all subarray in 
    //T.C --> O(N^3),  S.C --> O(1)
    int n = arr.size(), ans = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int sum = 0;
            for(int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if(sum == 0)
            {
                ans = max(ans, j - i + 1);
            }
        }
    }
    return ans;
}

int LargestSubarrayWith0SumBetter(vector<int>&arr)
{
    //Better Approach: generating subarray in N^2 T.C
    //T.C --> O(N^2),  S.C --> O(1)
    int n = arr.size(), ans = 0;

    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += arr[j];
            if(sum == 0)
            {
                max(ans, j - i + 1);
            }
        }
    }
    return ans;
}

int LargestSubarrayWith0SumOptimal(vector<int>&arr)
{
    int n = arr.size();
    int ans = -1;
    map<int, int> mp;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum == 0)
        {
            ans = i + 1;
        }
        else
        {
            if(mp.find(sum) != mp.end())
            {
                ans = max(ans, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
    }
    if(ans == -1)return 0;
    return ans;
}

int main()
{
    vector<int> arr1 = {1, 0, -4, 3, 1, 0};
    vector<int> arr2 = {2, 10, 4};
    vector<int> arr3 = {15, -2, 2, -8, 1, 7, 10, 23};
    
    int ans = -1;

    ans = LargestSubarrayWith0SumBrute(arr1);
    cout<<ans<<"\n";

    ans = LargestSubarrayWith0SumBetter(arr2);
    cout<<ans<<"\n";

    ans = LargestSubarrayWith0SumOptimal(arr3);
    cout<<ans<<"\n";

    return 0;
}