#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> majorityElementIIBrute(vector<int>&arr)
{
    //Brute Force: Counting the occurance of each element and pushing it in ans array if count > n/3
    //T.C --> O(N^2), S.C --> O(1) [at max 2 elements can be return]
    int n = arr.size();
    vector<int> ans;

    for(int i = 0; i < n; i++)
    {
        int count = 0;

        for(int j = 0; j < n; j++)
        {
            if(arr[j] == arr[i])count++;
        }
        if(count > (n/3))
        {
            //at max there can only be 2 elements in ans thus current element having
            //count > n/3 should only be pushed in ans array if either the ans array is
            //empty or the previous number was different than current number
            if(ans.empty() || ans[0] != arr[i])
            {
                ans.push_back(arr[i]);
                if(ans.size() == 2)break;
            }
        }
    }

    return ans;
}

vector<int> majorityElementIIBetter(vector<int> &arr)
{
    //Better Approach: using map to store the frequency of each elemet
    //T.C --> O(N LogN), S.C --> O(N) [map]
    int n = arr.size();
    map<int, int> mp;
    vector<int> ans;

    for(int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        
        if(mp[arr[i]] > (n/3))
        {
            ans.push_back(arr[i]);
        }

        if(ans.size() == 2)break;
    }

    return ans;
}

vector<int> majorityElementIIOptimal(vector<int>&arr)
{
    //Optimal Approach: using the same idea as majority element >n/2.
    //T.C --> O(N), S.C --> O(1)
    int n = arr.size();
    vector<int> ans;
    int count1 = 0, count2 = 0, ele1 = -1, ele2 = -1;

    for(int i = 0; i < n; i++)
    {
        if(count1 == 0 && ele2 != arr[i])
        {
            count1 = 1, ele1 = arr[i];
        }
        else if (count2 == 0 && ele1 != arr[i])
        {
            count1 = 1, ele1 = arr[i];
        }
        else if(ele1 == arr[i])
        {
            count1++;
        }
        else if(ele2 == arr[i])
        {
            count2++;
        }
        else
        {
            count1--, count2--;
        }
    }

    int count11 = 0, count22 = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == ele1)count11++;
        if(arr[i] == ele2)count22++;
    }
    if(count11 > (n/3))ans.push_back(ele1);
    if(count22 > (n/3))ans.push_back(ele2);

    return ans;
}

void printArray(vector<int>&arr)
{
    cout<<"ans Array size is: "<<arr.size()<<"\n";
    cout<<"Elements having count > n/3 are: \n";
    for(auto it: arr)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr = {15,15,15,30,30,30,15,30,10,10,10};

    vector<int> ans1 = majorityElementIIBrute(arr);
    printArray(ans1);

    vector<int> ans2 = majorityElementIIBetter(arr);
    printArray(ans2);

    vector<int> ans3 = majorityElementIIOptimal(arr);
    printArray(ans3);

    return 0; 
}