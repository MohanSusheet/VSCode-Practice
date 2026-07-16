#include<iostream>
#include<limits>
#include <climits>

using namespace std;

class TreeNode
{
public: 
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(){} //Empty Constructor
    TreeNode(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(int val, TreeNode* left, TreeNode* right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

int getMaxPathSum(TreeNode* root, int& maxxPathSum)
{
    if(root == NULL)return 0;

    // for cases like [2,-1]. We drop the path/paths that return a -ve sum.
    int leftMaxSum = max(0, getMaxPathSum(root->left, maxxPathSum));
    int rightMaxSum = max(0, getMaxPathSum(root->right, maxxPathSum));
    //At the time of comparing we take the sum of all 3 values i.e. 
    //cur node val + leftMaxSum + rightMaxSum
    maxxPathSum = max(maxxPathSum, root->val + leftMaxSum + rightMaxSum);


    /* At the time of returning we only return the max(leftMaxSum, rightMaxSum), 
    So that a path can be followed (where each node is visited only once) otherwise this condition will get contradicted. */
    return root->val + max(leftMaxSum, rightMaxSum);
}

int maxPathSum(TreeNode* root)
{
    //Core Intuition: Using the same logic used for Max Height
    //Instead of Height: we Return max(leftSum, RightSum) and hold the maximum sum in global variable
    //T.C --> O(N), S.C --> O(H) ~~ O(N) [in worst case i.e. skewed Tree]

    int maxxPathSum = INT_MIN;
    getMaxPathSum(root, maxxPathSum);
    return maxxPathSum;
}


int main()
{
    TreeNode* root = new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    cout<<"max path sum: "<<maxPathSum(root);

    return 0;
}