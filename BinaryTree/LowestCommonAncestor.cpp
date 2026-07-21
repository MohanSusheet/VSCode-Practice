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

bool rootToNodePath(TreeNode* root, int target, vector<TreeNode*>&path)
{
    if(root == NULL)return false;

    path.push_back(root);
    if(root->val == target)return true;

    if(rootToNodePath(root->left, target, path) || rootToNodePath(root->right, target, path))return true;

    path.pop_back();
    return false;
}

TreeNode* lowestCommonAncestorBrute(TreeNode* root, TreeNode* p, TreeNode*q)
{
    //Naive approach: traverse and store the paths from root to p and q nodes in an array. Compare the paths, the last common node in the paths is the LCA of p and q.
    //T.C--> O(), S.C --> 
    // Time Complexity:
    // getRootToNodePath(root, p)  -> O(n)
    // getRootToNodePath(root, q)  -> O(n)
    // Compare both paths          -> O(h)
    // Overall                     -> O(n)

    // Space Complexity:
    // path1 + path2 + recursion stack
    // = O(h)
    // Worst case: O(n)
    // Balanced tree: O(log n) 
    vector<TreeNode*> path1, path2;
    TreeNode* ans = nullptr;
    rootToNodePath(root, p->val, path1);
    rootToNodePath(root, q->val, path2);

    for(int i = 0; i < min(path1.size(), path2.size()); i++)
    {
        if(path1[i] == path2[i])ans = path1[i];
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

    TreeNode* lca = lowestCommonAncestorBrute(root, new TreeNode(11), new TreeNode(19));

    cout<<"Lowest Common Ancestor of 11 and 19 is: "<<lca->val;

    return 0;
}