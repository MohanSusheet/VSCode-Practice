#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(vector<vector<int>>&arr)
{
    for(auto it: arr)
    {
        for(auto x: it)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

void rotateImageBy90Brute(vector<vector<int>>& arr)
{
    //Optimal Approach: Transpose the matrix + reverse each row 
    //T.C --> O(n * m), S.C -> O(1) [m = n as rotation is possible only for square matrix]
    int n = arr.size(), m = arr[0].size();
    vector<vector<int>> rotated;

    for(int j = 0; j < m; j++)
    {
        vector<int> temp;
        for(int i = n-1; i >= 0; i--)
        {
            temp.push_back(arr[i][j]);
        }
        rotated.push_back(temp);
    }

    for(int i=0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            arr[i][j] = rotated[i][j];
        }
    }
}

void rotateImageBy90Optimal(vector<vector<int>> &arr)
{
    int n = arr.size();
    //traversing the upper trinagle and swapping the values with lower triangle
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    //reversing each row
    for(int i = 0; i < n; i++)
    {
        reverse(arr[i].begin(), arr[i].end());
    }
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printArray(arr);
    // rotateImageBy90Brute(arr);
    rotateImageBy90Optimal(arr);
    printArray(arr);
    return 0;
}