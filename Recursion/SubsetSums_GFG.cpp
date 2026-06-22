#include<iostream>
#include<vector>

using namespace std;

/*
PROBLEM STATEMENT (GFG):
Given an array nums of integers, return the sums of all subsets in the list. Return the sums in any order.
*/

void generateSubsets(vector<int>&nums, int i, int &sum, vector<int>&ans)
{
    if(i == nums.size())
    {
        ans.push_back(sum);
        return;
    }

    generateSubsets(nums, i+1, sum, ans);
    sum += nums[i];
    generateSubsets(nums, i+1, sum, ans);
    sum -= nums[i];
}

int main()
{
    vector<int> nums = {5, 6, 7};

    vector<int> ans;
    int sum = 0;

    generateSubsets(nums, 0, sum, ans);
    cout<<endl;
    for(auto it: ans)
    {
        cout<<it<<" ";
        // cout<<endl;
    }

    return 0;
}