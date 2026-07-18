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

int bottomLeftTreeValueBFS(TreeNode* root)
{
    if(root == NULL)return -1;
    int ans = root->val;
    int level = 0;

    queue<pair<TreeNode*, int>>q;

    q.push({root, 0});

    while(!q.empty())
    {
        pair<TreeNode*, int> node = q.front();
        q.pop();

        int l = node.second;

        if(l > level)
        {
            ans = node.first->val;
            level = l;
        }

        if(node.first->left)q.push({node.first->left, l + 1});
        if(node.first->right)q.push({node.first->right, l + 1});
    }

    return ans;
}

int dfs(TreeNode* root, int l, int& level, int& ans)
{
    if(root == NULL)return ans;

    if(l > level)
    {
        ans = root->val;
        level = l;
    }

    dfs(root->left, l + 1, level, ans);
    dfs(root->right, l + 1, level, ans);

    return ans;
}

int bottomLeftTreeValueDFS(TreeNode* root)
{
    int level = -1, ans = -1;
    return dfs(root, 0, level, ans);
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

    int result1 = bottomLeftTreeValueBFS(root);
    int result2 = bottomLeftTreeValueDFS(root);

    cout<<result1<<" && "<<result2;

    return 0;
}