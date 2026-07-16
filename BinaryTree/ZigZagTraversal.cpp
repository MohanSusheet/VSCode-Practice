#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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

void print2DArray(vector<vector<int>>&arr)
{
    for(auto it: arr)
    {
        for(auto i: it)cout<<i<<" ";
    }
    cout<<endl;
}

vector<vector<int>> myZigZagTraversal(TreeNode* root)
{
    //Using Level order traversal
    //T.C --> O(N), s.C --> O(Width) [used by queue, ignoring the ds used for return the ans]
    vector<vector<int>> ans;

    if(root == NULL)return ans;

    queue<TreeNode*> q;
    q.push(root);
    bool rev = false;

    while(!q.empty())
    {
        int size = q.size();
        vector<int> cur;

        for(int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            cur.push_back(node->val);

            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }

        if(rev)
        {
            reverse(cur.begin(), cur.end());
            ans.push_back(cur);
        }
        else ans.push_back(cur);

        rev = !rev;
    }

    return ans;
}

vector<vector<int>> striverZigZagTraversal(TreeNode* root)
{
    //Using Level order traversal
    //T.C --> O(N), s.C --> O(Width) [used by queue, ignoring the ds used for return the ans]
    vector<vector<int>> ans;

    if(root == NULL)return ans;

    queue<TreeNode*> q;
    q.push(root);
    bool rev = false;

    while(!q.empty())
    {
        int size = q.size();
        vector<int> cur(size);

        for(int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            int index = rev? size - i - 1 : i;
            cur[index] = node->val;

            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        ans.push_back(cur);
        rev = !rev;
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

    vector<vector<int>> zigZag1 = myZigZagTraversal(root);
    vector<vector<int>> zigZag2 = striverZigZagTraversal(root);

    print2DArray(zigZag1);
    print2DArray(zigZag2);
    return 0;
}