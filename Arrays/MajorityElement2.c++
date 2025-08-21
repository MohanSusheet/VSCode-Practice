#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<math.h>
#include <climits>
using namespace std;

void printArray(vector<int>&arr)
{
    for(auto it: arr)cout<<it<<" ";
    cout<<endl;
}

vector<int> MajorityElemet2BruteApproach(vector<int>&arr)
{
    //T.C -> O(n^2) + O(n*log n)[insertion in set], S.C -> O(n) to return the ans
    int n = arr.size();
    set<int> st;
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        int count = 0;
        for(int j = i; j < n; j++)
        {
            if(arr[j] == arr[i])
            {
                count++;
            }
        }
        if(count > floor(n / 3))
        {
            st.insert(arr[i]);
        }
    }

    for(auto it: st)
    {
        ans.push_back(it);
    }
    return ans;
}
vector<int> MajorityElemet2Better1(vector<int> &arr)
{
    //T.C -> O(n^2) , S.C -> O(n) to return the ans
    int n = arr.size();
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        int count = 0;
        for(int j = 0; j < n; j++)
        {
            if(arr[j] == arr[i])count++;
        }
        if(ans.size() == 0 || ans[0] != arr[i])
        {
            ans.push_back(arr[i]);
        }
        if(ans.size() == 2)break;
    }

    return ans;
}
vector<int> MajorityElemet2Better2(vector<int> &arr)
{
    //T.C -> O(N) + O(N * Log N) ~ O(N*LogN) , S.C -> O(N)
    int n = arr.size();
    map<int, int> mp;
    vector<int> ans;

    for(int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        if(ans.size() == 0 || (ans[0] != arr[i] && mp[arr[i]] > (n/3)))
        {
            ans.push_back(arr[i]);
        }
        if(ans.size() == 2)break;
    }

    return ans;
}
vector<int> MajorityElemet2Optimal(vector<int> &arr)
{
    //Optimal Approach: Extended Boyer Moore’s Voting Algorithm (extending majorityElementI logic)
    //T.C -> O(N) , S.C -> (1)
    int n = arr.size();
    vector<int> ans;
    int ele1 = INT_MIN, count1 = 0, ele2 = INT_MIN, count2 = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(count1 == 0 && arr[i] != ele2)
        {
            ele1 = arr[i];
            count1 = 1;
        }
        else if(count2 == 0 && arr[i] != ele1)
        {
            ele2 = arr[i];
            count2 = 1;
        }
        else if(arr[i] == ele1)
        {
            count1++;
        }
        else if(arr[i] == ele2)
        {
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }

    int count11 = 0, count22 = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == ele1)count11++;
        else if(arr[i] == ele2)count22++;
    }
    if(count11 > (n/3))ans.push_back(ele1);
    if(count22 > (n/3))ans.push_back(ele2);

    return ans;

}

int main() {
    vector<int> arr = {2, 1, 1, 3, 1, 4, 2, 2};
    
    vector<int> ans = MajorityElemet2BruteApproach(arr);
    printArray(ans);
    vector<int> ans1 = MajorityElemet2Better1(arr);
    printArray(ans1);
    vector<int> ans2 = MajorityElemet2Better2(arr);
    printArray(ans2);
    vector<int> ans3 = MajorityElemet2Optimal(arr);
    printArray(ans3);
    cout << "\n";
    return 0;
}
