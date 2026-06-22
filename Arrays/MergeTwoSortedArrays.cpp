#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    void MergeSortedArraysBrute(vector<int>&nums1, int n, vector<int>&nums2, int m)
    {
        //Brute Appraoch: merging the elements of second array to the first array and then Sorting the first array.
        //T.C --> O(M) [as we iterate on the second array only] + O(N+M)(Log(N+M)), S.C -> O(1) no extra space is being used.

        for(int i = 0; i < m; i++)
        {
            nums1.push_back(nums2[i]);
        }

        sort(nums1.begin(), nums1.end());
    }


    void MergeSortedArraysBetter(vector<int>&nums1, int n, vector<int>&nums2, int m)
    {
        //Better Appraoch: merging the elements of the 2 arrays into a third array using 2 POINTERS.
        //T.C --> O(N + M), S.C -> O(N+M) extra space is being used.
        vector<int> merged;
        
        int i = 0, j = 0;

        while(i < n && j < m)
        {
            if(nums1[i] <= nums2[j])
            {
                merged.push_back(nums1[i++]);
            }
            else
            {
                merged.push_back(nums2[j++]);
            }
        }

        while(i < n)
        {
            merged.push_back(nums1[i++]);
        }
        while(j < m)
        {
            merged.push_back(nums2[j++]);
        }
        nums1.clear();
        nums1 = merged;
    }


};

int main()
{
    Solution Sol = Solution();
    vector<int> nums1 = {};
    return 0;
}