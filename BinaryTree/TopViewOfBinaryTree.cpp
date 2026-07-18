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

vector<int> topViewOfBinaryTree(TreeNode* root)
{
    //T.C --> O(N)*log N [multiset], S.C -->O(N)[map] + O(N)[queue] ~~ O(N) 
    vector<int> ans;
    if(root == NULL)return ans;
    
    map<int,int> m;
    queue<pair<int,TreeNode*>>q;
    
    q.push({0, root});
    
    while(!q.empty())
    {
        pair<int, TreeNode*> node = q.front();
        q.pop();

        if(m.find(node.first) == m.end())m[node.first] = node.second->val;
        if(node.second->left)q.push({node.first - 1, node.second->left});
        if(node.second->right)q.push({node.first + 1, node.second->right});
    }

    for(auto it: m)
    {
        ans.push_back(it.second);
    }
    
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

    vector<int> result = topViewOfBinaryTree(root);

    cout<<"Top view of Binary Tree: ";
    for(auto it: result)
    {
        cout<<it<<" ";
    }
    
    return 0;
}