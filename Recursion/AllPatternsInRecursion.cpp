#include<iostream>
#include<vector>

using namespace std;

void generateSubsequenceWithSumK(vector<int>&arr, int i, vector<int>&cur, int sum, int target, vector<vector<int>>&ans)
{
    if(i == arr.size())
    {
        if(sum == target)
        {
            ans.push_back(cur);
        }
        return;
    }

    cur.push_back(arr[i]);
    sum += arr[i];
    generateSubsequenceWithSumK(arr, i+1, cur, sum, target, ans);
    cur.pop_back();
    sum -= arr[i];
    generateSubsequenceWithSumK(arr, i+1, cur, sum, target, ans);
}

bool generateSubsequenceWithSumKOnly1Subsequence(vector<int>&arr, int i, vector<int>&cur, int sum, int target, vector<vector<int>>&ans)
{
    if(i == arr.size())
    {
        if(sum == target)
        {
            ans.push_back(cur);
            return true;
        }
        return false;
    }

    cur.push_back(arr[i]);
    sum += arr[i];
    if(generateSubsequenceWithSumKOnly1Subsequence(arr, i+1, cur, sum, target, ans))return true;
    cur.pop_back();
    sum -= arr[i];
    if(generateSubsequenceWithSumKOnly1Subsequence(arr, i+1, cur, sum, target, ans))return true;

    return false;
}

int countSubsequenceWithSumK(vector<int>&arr, int i, vector<int>&cur, int sum, int target)
{
    if(i == arr.size())
    {
        if(sum == target)
        {
            return 1;
        }
        return 0;
    }

    cur.push_back(arr[i]);
    sum += arr[i];
    int left = countSubsequenceWithSumK(arr, i+1, cur, sum, target);
    cur.pop_back();
    sum -= arr[i];
    int right = countSubsequenceWithSumK(arr, i+1, cur, sum, target);

    return left + right;
}

int main()
{
    vector<int> arr = {1,2,1};
    vector<int> cur;
    vector<vector<int>>ans; 
    int sum = 0;
    
    // generateSubsequenceWithSumK(arr, 0, cur, sum, 2, ans);
    
    generateSubsequenceWithSumKOnly1Subsequence(arr, 0, cur, sum, 2, ans);
    
    cout<<"size : "<<ans.size()<<"\n";
    for(auto it: ans)
    {
        for(auto i: it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
    
    int count = countSubsequenceWithSumK(arr, 0, cur, sum, 2);
    cout<<"number of subsequence with sum K: "<< count;
    return 0;
}