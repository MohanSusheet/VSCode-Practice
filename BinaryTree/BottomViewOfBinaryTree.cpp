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

vector<int> bottomViewOfBinaryTree(TreeNode* root)
{
    //Approach: Using the VERTICAL LINE concept to map each node to its vertical
    //ans since we wan the bottom view that means we need the very last node on each vertical line 
    //T.C --> O(N)*log N [map], S.C -->O(N)[map] + O(N)[queue] ~~ O(N) 
    vector<int> ans;
    if(root == NULL)return ans;
    
    map<int, int> nodeToLineMapping;
    queue<pair<int, TreeNode*>> q;
    q.push({0, root});

    while(!q.empty())
    {
        pair<int, TreeNode*> node = q.front();
        q.pop();
        int vertical = node.first;
        //Since we want the last node of every vertical line, we can keep on overriding the value in the map
        nodeToLineMapping[vertical] = node.second->val;
        if(node.second->left)q.push({vertical - 1, node.second->left});
        if(node.second->right)q.push({vertical + 1, node.second->right});
    }
    
    for(auto it: nodeToLineMapping)
    {
        ans.push_back(it.second);
    }
    /*The deepest nodes are 6 and 11, both at the same depth.
    With the standard BFS implementation used in most interview questions and GFG, 
    the node visited later replaces the earlier one. Since 11 is visited after 6, the bottom view uses*/
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

    vector<int> result = bottomViewOfBinaryTree(root);

    cout<<"Top view of Binary Tree: ";
    for(auto it: result)
    {
        cout<<it<<" ";
    }
    
    return 0;
}