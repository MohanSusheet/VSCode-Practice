#include <iostream>
#include <vector>
#include <set>
using namespace std;

int removeDuplicatesBrute(vector<int> &arr)
{
    int n = arr.size();
    set<int> st;

    for(int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }
    int set_size = st.size();

    int i = 0;
    for(auto it: st)
    {
        arr[i++] =  it;
    }

    return set_size;
}

int removeDuplicatesBetter(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp;
    temp.push_back(arr[0]);

    for(int i = 1; i < n; i++)
    {
        if(arr[i] != temp.back())
        {
            temp.push_back(arr[i]);
        }
    }

    int i = 0;
    for(auto it: temp)
    {
        arr[i++] = it;
    }
    return temp.size();
}

int removeDuplicatesOptimal(vector<int> &arr)
{
    int n = arr.size();

    int i = 0, j = 0;

    while(j < n)
    {
        if(arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
        j++;
    }

    return i + 1;
}

void printArray(vector<int>&arr, int last_index)
{
    for(int i = 0; i < last_index; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> arr = {1,1,1,2,2,3,3,3,3,4,4};

    int last_index1 = removeDuplicatesBrute(arr);
    printArray(arr, last_index1);

    arr = {1,1,1,2,2,3,3,3,3,4,4};
    int last_index2 = removeDuplicatesBetter(arr);
    printArray(arr, last_index2);

    arr = {1,1,1,2,2,3,3,3,3,4,4};
    int last_index3 = removeDuplicatesOptimal(arr);
    printArray(arr, last_index3);
}