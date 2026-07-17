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

vector<vector<int>> verticalOrderTraversal(TreeNode* root)
{
    //T.C --> O(N)*log N [multiset], S.C -->O(N)[map] + O(N)[queue] ~~ O(N) 
    vector<vector<int>> ans;
    if(root == NULL)return ans;

    map<int, map<int, multiset<int>>> mapping;

    queue<pair<TreeNode*, pair<int, int>>> q;

    q.push({root, {0, 0}});

    while(!q.empty())
    {
        int size = q.size();

        for(int i = 0; i < size; i++)
        {
            pair<TreeNode*, pair<int, int>> node = q.front();
            q.pop();

            int vertical = node.second.first;
            int level = node.second.second;

            mapping[vertical][level].insert(node.first->val);

            if(node.first->left)q.push({node.first->left, {vertical - 1, level + 1}});
            if(node.first->right)q.push({node.first->right, {vertical + 1, level + 1}});
        }
    }

    for(auto it: mapping)
    {
        vector<int>temp;
        for(auto i: it.second)
        {
            for(auto k: i.second)temp.push_back(k);
        }
        ans.push_back(temp);
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

    vector<vector<int>> result = verticalOrderTraversal(root);

    cout<<"Vertical Order Traversal: ";
    for(auto it: result)
    {
        for(auto i: it)cout<<i<<" ";
        cout<<endl;
    }
    
    return 0;
}