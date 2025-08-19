#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<int> UnionOfSortedArrays1(vector<int>&arr1, vector<int> &arr2)
{
    //Solution 1: Using map to keep track of the elements present in arra1 and array2
    //combinedly and then inserting those elements in unionArray irrespective of their
    //frequency making sure all the elements are taken only once.
    //T.C -> O((N+M)log(N+M)), S.C --> O(N + M)
    int n = arr1.size(), m = arr2.size();
    map<int, int> mp;
    vector<int> unionArray;

    for(int i = 0; i < n; i++)
    {
        mp[arr1[i]]++;
    }
    for(int j = 0; j < m; j++)
    {
        mp[arr2[j]]++;
    }

    for(auto it: mp)
    {
        unionArray.push_back(it.first);
    }
    
    return unionArray;
}

vector<int> UnionOfSortedArrays2(vector<int>&arr1, vector<int>&arr2)
{
    //Solution 2: Using set to get unique elements out of both the arrays.
    //T.C -> O((N+M)log(N+M)), S.C --> O(N + M) 
    int n = arr1.size(), m = arr2.size();
    vector<int> unionArray;
    set<int> s;

    for(int i = 0; i < n; i++)
    {
        s.insert(arr1[i]);
    }
    for(int j = 0; j < m; j++)
    {
        s.insert(arr2[j]);
    }

    for(auto it: s)
    {
        unionArray.push_back(it);
    }

    return unionArray;
}

vector<int> UnionOfSortedArraysOptimal(vector<int>&arr1, vector<int>&arr2)
{
    //Optimal Approach: Using 2 pointers 
    //T.C --> O(N + M), S.C --> O(N + M)
    int n = arr1.size(), m = arr2.size();
    int i = 0, j = 0;
    vector<int> unionArray;
    
    while(i < n && j < m)
    {
        if(arr1[i] <= arr2[j])
        {
            if(unionArray.size() == 0 || unionArray.back() != arr1[i])
            {
                unionArray.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if(unionArray.size() == 0 || unionArray.back() != arr2[j])
            {
                unionArray.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(i < n)
    {
        unionArray.push_back(arr1[i++]);
    }
    while(j < m)
    {
        unionArray.push_back(arr2[j++]);
    }

    return unionArray;
}

void printArray(vector<int> &arr)
{
    int n = arr.size();
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr1 = {1,2,3,4,5,6,7,8,9,10};
    vector<int> arr2 = {2,3,4,4,5,11,12};

    vector<int> unionArray1 = UnionOfSortedArrays1(arr1, arr2);
    printArray(unionArray1);

    vector<int> unionArray2 = UnionOfSortedArrays2(arr1, arr2);
    printArray(unionArray2);

    vector<int> unionArray3 = UnionOfSortedArraysOptimal(arr1, arr2);
    printArray(unionArray3);
    return 0;
}