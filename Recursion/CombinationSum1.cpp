#include<iostream>
#include<vector>
#include<set>

using namespace std;


void generateCombinationsMySolution(vector<int>&nums, int i, int& sum, vector<int>&cur, int target, set<vector<int>>&s)
{
    if(sum > target)return;
    if(sum == target)
    {
        s.insert(cur);
        return;
    }
    if(i == nums.size())
    {
        return;
    }

    sum += nums[i];
    cur.push_back(nums[i]);
    generateCombinationsMySolution(nums, i, sum, cur, target, s);
    // generateCombinations(nums, i+1, sum, cur, target, s);
    sum -= nums[i];
    cur.pop_back();
    generateCombinationsMySolution(nums, i+1, sum, cur, target, s);
}

//Classic backtracking approach with no duplicates generation
void generateCombinationsClassicApproach(vector<int>&nums, int i, vector<int>&cur, int target, vector<vector<int>>&ans)
{
    if(i == nums.size())
    {
        if(target == 0)
        {
            ans.push_back(cur);
        }
        return;
    }

    if(nums[i] <= target)
    {
        cur.push_back(nums[i]);
        generateCombinationsClassicApproach(nums, i, cur, target - nums[i], ans);
        cur.pop_back();
    }
    generateCombinationsClassicApproach(nums, i+1, cur, target, ans);
}

vector<vector<int>> combinationSum(vector<int>&nums, int target)
{
    vector<vector<int>> ans;
    vector<int> cur;

    /*these below 4 lines were implementation of the approach i had in my mind using SET and 3 calls 
        1. Take and stay at same index
        2. Take and move to next index (The second call is redundant.)
        3. Don't take and move to next index
    Also this approach generates duplicates, hence required SET to clean up the mess.
    the purpose of 2nd call will eventually be fulfilled by 1 and 3 only. 2n is not needed
    */ 
    // set<vector<int>> s;
    // int sum = 0;
    // generateCombinationsMySolution(nums, 0, sum, cur, target, s);
    // return vector<vector<int>>(s.begin(), s.end());

    generateCombinationsClassicApproach(nums, 0, cur, target, ans);
    return ans;
    
}

int main()
{
    vector<int> nums = {2,3,6,7};
    int target = 7;

    vector<vector<int>> uniqueCombinations = combinationSum(nums, target);

    for(auto it: uniqueCombinations)
    {
        cout<<"{";
        for(auto i: it)
        {
            cout<<i<<" ";
        }
        cout<<"}"<<endl;
    }
    return 0;
}