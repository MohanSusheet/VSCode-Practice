#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArray(vector<vector<int>> &arr)
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

void print(vector<int>&arr)
{
    for(auto i: arr)
    {
        cout<<i<<" ";
    }
}

vector<int> spiralMatrix(vector<vector<int>>&arr)
{
    int n = arr.size(), m = arr[0].size();
    int left = 0, right = m - 1, top = 0, bottom = n-1;
    vector<int>ans;
    while(left <= right && top <= bottom)
    {
        for(int i = left; i <= right; i++)
        {
            ans.push_back(arr[top][i]);
        }
        top++;
        for(int i = top; i <= bottom; i++)
        {
            ans.push_back(arr[i][right]);
        }
        right--;
        if(top <= bottom)
        {
            for(int i = right; i >= left; i--)
            {
                ans.push_back(arr[bottom][i]);
            }
            bottom--;
        }
        
        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
            {
                ans.push_back(arr[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1,2,3,4,5, 6}, {20,21,22,23,24,7}, {19,32,33,34,25,8}, {18,31,36,35,26,9}, {17,30,29, 28,27,10}, {16,15,14,13,12,11}};
    printArray(arr);
    vector<int> ans = spiralMatrix(arr);
    print(ans);
    return 0;
}