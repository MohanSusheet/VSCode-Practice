#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void printArray(vector<vector<int>>&arr)
{
    for(auto it: arr)
    {
        for(auto i: it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> ThreeSumBrute(vector<int>&arr)
{
    int n = arr.size();
    set<vector<int>> s;

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                if(arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(s.begin(), s.end());

    return ans;
}

vector<vector<int>> ThreeSumBetter(vector<int>&arr)
{
    //Better Approach: using hashing to find the target ( 0 - (nums[i] + nums[j]))
    //to get rid of the third loop.
    //to make sure only unique triplets are selected we only store the elements
    //between ith and jth element in the hashmap/hashset.
    //T.C --> O(N^2 * O(logN)), S.C --> O(N)[map] + O(2 * O(Unique triplets)) [set and ans vector]
    int n = arr.size();
    set<vector<int>> s;

    for(int i = 0; i < n; i++)
    {
        map<int, int> mp;
        for(int j = i + 1; j < n; j++)
        {
            int target = - (arr[i] + arr[j]);
            if(mp.find(target) != mp.end())
            {
                vector<int> temp = {arr[i], arr[j], target};
                sort(temp.begin(), temp.end());
                s.insert(temp);
            }
            mp[arr[j]]++;
        }
    }
    
    vector<vector<int>> ans(s.begin(), s.end());

    return ans;
}

vector<vector<int>> ThreeSumOptimal(vector<int>&arr)
{
    //Optimal Approach: Getting rid of the set used to store unique triplets.
    //Sort the array first and then devising an algorithm to get all the unique triplets
    //T.C --> O(N^2 + O(N * logN)), S.C --> O(Unique triplets) [ans vector]
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++)
    {
        if(i > 0 && arr[i] == arr[i-1])continue;
        int j = i + 1, k = n-1;
        
        while(j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];

            if(sum == 0)
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++; k--;
                while(j < k && arr[j] == arr[j-1])j++;
                while(j < k && arr[k] == arr[k+1])k--;
            }
            else if(sum < 0)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {-1,0,1,2,-1,-4};

    vector<vector<int>> ans1 = ThreeSumBrute(arr);
    printArray(ans1);
    cout<<endl;

    vector<vector<int>> ans2 = ThreeSumBetter(arr);
    printArray(ans2);
    cout<<endl;

    vector<vector<int>> ans3 = ThreeSumOptimal(arr);
    printArray(ans3);
    cout<<endl;

    return 0;
}