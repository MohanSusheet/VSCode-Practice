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

bool isLeaf(TreeNode* root)
{
    if(root->left == NULL && root->right == NULL)return true;

    return false;
}

void addLeft(TreeNode* root, vector<int>&ans)
{
    if(root == NULL)return;

    TreeNode* cur = root->left;

    while(cur)
    {
        if(!isLeaf(cur))ans.push_back(cur->val);
        if(cur->left)cur = cur->left;
        else cur = cur->right; 
    }
}

void addRight(TreeNode* root, vector<int>&ans)
{
    if(root == NULL)return;

    TreeNode* cur = root->right;
    vector<int>temp;

    while(cur)
    {
        if(!isLeaf(cur))temp.push_back(cur->val);
        if(cur->right)cur = cur->right;
        else cur = cur->left;
    }

    for(int i = temp.size() - 1; i >= 0; i--)ans.push_back(temp[i]);
}

void addLeaf(TreeNode* root, vector<int> &ans)
{
    if(root == NULL)return;
    
    if(isLeaf(root))ans.push_back(root->val);
    
    addLeaf(root->left, ans);
    addLeaf(root->right, ans);
}


vector<int> boundaryTraversal(TreeNode* root)
{
    vector<int> ans;
    if(root == NULL)return ans;

    if(!isLeaf(root))ans.push_back(root->val);

    addLeft(root, ans);
    addLeaf(root, ans);
    addRight(root, ans);

    return ans;
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

    vector<int> result = boundaryTraversal(root);

    cout<<"Boundary Traversal: ";
    for(auto it: result)cout<<it<<" ";
    
    return 0;
}