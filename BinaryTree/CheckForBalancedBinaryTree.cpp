#include<iostream>

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

int calculateHeight(TreeNode* root)
{
    if(root == NULL)return 0;

    int lh = calculateHeight(root->left);
    int rh = calculateHeight(root->right);

    return 1 + max(lh, rh);
}

bool isBalancedBinaryTreeBrute(TreeNode* root)
{
    //Brute Solution: checking the condition at each node by getting the height of respective left and right Subtree
    //T.C --> O(N^2)
    //S.C --> O()
    if(root == NULL)return true;

    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    //CONDITION for Balanced BINARY TREE -----> Height(left Subtree) - Heigh(right Subtree) <= 1
    //i.e. the max height difference b/w the left and right subtree can be 1. else the tree is not balanced
    if(abs(leftHeight - rightHeight) > 1)return false;

    bool checkLeft = isBalancedBinaryTreeBrute(root->left);
    bool checkRight = isBalancedBinaryTreeBrute(root->right);

    if(!checkLeft || !checkRight)return false;  //if any of the subTree failed the condition return false
    
    return true;
}

int check(TreeNode* root)
{
    ////Optimal Approach: using the height approach to determine whether at any point 
    //the diff b/w the height of LeftSubTree and RightSubTree is more than 1, we return -1;
    //T.C --> O(N), S.C --> O(N)
    if(root == NULL)return 0;

    int leftHeight = check(root->left);
    int rightHeight = check(root->right);

    if(leftHeight == -1 || rightHeight == -1)return -1;

    if(abs(leftHeight - rightHeight) > 1)return -1;

    return 1 + max(leftHeight, rightHeight);
}

bool isBalancedBinaryTreeOpimtal(TreeNode* root)
{
    return check(root) != -1;
}

int main()
{
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    // root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(10);
    // root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    cout<<"Is Tree Balanced: "<<isBalancedBinaryTreeBrute(root)<<"\n";

    cout<<"Is Tree Balanced: "<<isBalancedBinaryTreeOpimtal(root);

    return 0;
}