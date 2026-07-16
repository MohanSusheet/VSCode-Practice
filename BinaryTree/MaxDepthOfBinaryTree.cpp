#include<iostream>
#include<vector>
#include<queue>

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

int maxHeightOfBinaryTreeRecursive(TreeNode* root)
{
    //T.C --> O(N)
    //S.C --> O(Height] (recursion stack space will hold at max the height of the tree)
    if(root == NULL)return 0;

    int left = maxHeightOfBinaryTreeRecursive(root->left);
    int right = maxHeightOfBinaryTreeRecursive(root->right);

    return 1 + max(left, right);
}

int maxHeightOfBinaryTreeLOT(TreeNode* root)
{
    //T.C --> O(N)
    //S.C --> O(W)[width] in the worst case(as queue will hold all the node of the last level if the tree is a complete binary tree)
    int height = 0;
    if(root == NULL)return height;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        height++;
        for(int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            if(node->left != NULL)q.push(node->left);
            if(node->right != NULL)q.push(node->right);
        }
    }

    return height;
}


int main()
{
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);
    root->right->right->left->right = new TreeNode(19);

    cout<<maxHeightOfBinaryTreeRecursive(root)<<"\n";
    cout<<maxHeightOfBinaryTreeLOT(root); //Level Order Travers using Queue

    return 0;
}