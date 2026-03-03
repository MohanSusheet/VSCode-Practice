#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals)
    {
        int n = intervals.size();
        if(n <= 0)return {};
        vector<vector<int>> ans;
        //Sorting the intervals in order to handle cases where the succeeding sub-interval
        //is a part of the previous sub-interval entirely eg. [[1,7], [4, 7], [0, 0]]
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);

        for(int i = 1; i < n; i++)
        {
            if(ans.back()[1] >= intervals[i][0])
            {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

void print2DArray(vector<vector<int>>&arr)
{
    cout<<"{ ";
    for(auto it: arr)
    {
        cout<<"{ "<<it[0]<<", "<<it[1]<<" } ";
    }
    cout<<"}\n";
}

int main()
{
    Solution Sol = Solution();
    vector<vector<int>> intervals = {{7, 8}, {1, 5}, {2, 4}, {4, 6}};
    cout<<"Input Vector: \n";
    print2DArray(intervals);
    vector<vector<int>> ans = Sol.mergeIntervals(intervals);
    cout<<"Output Vector: \n";
    print2DArray(ans);

    return 0;
}