#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>

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

bool getPath(TreeNode* root, int target, vector<int>&ans)
{
    if(root == NULL)return false;

    ans.push_back(root->val);

    if(root->val == target)return true;

    if(getPath(root->left, target, ans) || getPath(root->right, target, ans))return true;

    ans.pop_back();
    return false;
}

vector<int> rootToNodePath(TreeNode* root, int target)
{
    vector<int> ans;
    if(root == NULL)return ans;

    getPath(root, target, ans);

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

    int targetNode = 7;
    vector<int> path = rootToNodePath(root, targetNode);  //Generic --> Specific qs : Root to Leaf
    cout<<"Root to node Path: ";
    for(auto it: path)cout<<it<<" ";

    return 0;
}