#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void generateCombinations(vector<int>&nums, int idx, int target, vector<int>&cur, vector<vector<int>>&ans)
{
    //T.C --> 2^n * K
    //S.C --> K * x
    if(target == 0)
    {
        ans.push_back(cur);
        return;
    }

    for(int i = idx; i < nums.size(); i++)
    {
        if(nums[i] > target)break;  //makes no sense to pursue this call as the sum will exceed the expected total.
        //Also all the next element will be >= nums[i]. Hence we break out.
        if(i > idx && nums[i] == nums[i-1])continue;  //this is the condition where we ensure that the next element we
        //are going to pick is not the same as the current element i.e. preventing duplicates.
        
        cur.push_back(nums[i]); //include the current element
        generateCombinations(nums, i+1, target - nums[i], cur, ans);  //call for next with nums[i] included
        cur.pop_back(); //nums[i] excluded.
        // generateCombinations(nums, i+1, target, cur, ans);
    }
}

int main()
{
    vector<int> nums = {10,1,2,7,6,1,5};
    int target = 8;

    vector<vector<int>> ans;
    vector<int> cur;

    sort(nums.begin(), nums.end());

    generateCombinations(nums, 0, target, cur, ans);

    cout<<"Size of ans array: "<< ans.size()<<endl;

    for(auto it: ans)
    {
        for(auto i: it)cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}