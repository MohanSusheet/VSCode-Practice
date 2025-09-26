#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

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

vector<vector<int>> FourSumBrute(vector<int>&arr, int target)
{
    //T.C --> O(n^4) * O(log(unique quadruplets)), S.C --> O((unique quadruplets))
    int n = arr.size();
    set<vector<int>> s;

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                for(int l = k+1; l < n; l++)
                {
                    long long sum = arr[i] + arr[j] + arr[k] + (long long)arr[l];
                    if(sum == target)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

vector<vector<int>> FourSumBetter(vector<int>&arr, int target)
{
    //Better Approach (Similar to 3 Sum): using hashmap/hashset to store the number between 
    //2nd and 3rd pointer (i.e. jth and kth respectively) 
    //T.C --> O(n^3) * O(log(unique quadruplets)), S.C --> O((unique quadruplets))
    int n = arr.size();
    set<vector<int>> s;

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            set<long long> st;
            for(int k = j + 1; k < n; k++)
            {
                long long sum = (long long)arr[i] + arr[j] + arr[k];
                long long remaining = target - sum;
                if(st.find(remaining) != st.end())
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], (int)remaining};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
                st.insert(arr[k]);
            }
        }
    }

    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

vector<vector<int>> FourSumOptimal( vector<int>&arr, int target)
{
    //Optimal (Similar to 3 Sum): getting rid of the hashset to look up in the array and to store the
    //unique triplets by Sorting the array
    //T.C --> O(n^3), S.C --> O((unique quadruplets)) [returning ans]
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++)
    {
        if(i > 0 && arr[i] == arr[i-1])continue;
        for(int j = i + 1; j < n; j++)
        {
            if(j > i + 1 && arr[j] == arr[j-1])continue;
            int k = j + 1, l = n-1;
            while(k < l)
            {
                long long sum = (long long)arr[i] + arr[j] + arr[k] + arr[l];
                if(sum == target)
                {
                    ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++, l--;
                    while(k < l && arr[k] == arr[k-1])k++;
                    while(k < l && arr[l] == arr[l+1])l--;
                }
                else if(sum < target)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {4,3,3,4,4,2,1,2,1,1};
    int target = 9;
    vector<vector<int>> ans1 = FourSumBrute(arr, target);
    printArray(ans1);
    cout<<endl;

    vector<vector<int>> ans2 = FourSumBetter(arr, target);
    printArray(ans2);
    cout<<endl;

    vector<vector<int>> ans3 = FourSumOptimal(arr, target);
    printArray(ans3);
    cout<<endl;

    return 0;
}