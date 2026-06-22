#include<iostream>
#include<vector>
using namespace std;

void f(vector<int>&nums, int i, vector<int>&cur, vector<vector<int>>&ans)
{
    if(i == nums.size())
    {
        ans.push_back(cur);
        return;
    }

    cur.push_back(nums[i]);
    f(nums, i+1, cur, ans);
    cur.pop_back();
    f(nums, i+1, cur, ans);
}

vector<vector<int>> generateSubsequences(vector<int>&nums)
{
    vector<vector<int>> ans;
    vector<int>cur;

    f(nums, 0, cur, ans);

    return ans;
}


int main()
{
    vector<int> arr = {3,1,2};
    vector<vector<int>> subsequences = generateSubsequences(arr);
    cout<<subsequences.size()<<"\n";

    for(auto it: subsequences)
    {
        for(auto i: it)cout<<"{"<<i<<"}"<<" ";
        cout<<endl;
    }
    return 0;
}