#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateRight(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int k = 2;
    rotateRight(nums, k);
    for (int num : nums) cout << num << " ";
    cout << "\n";
    return 0;
}
