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

void printArray(vector<int>&arr)
{
    for(int i: arr)cout<<i<<" ";
    cout<<endl;
}

vector<int> leftViewOfBinaryTreeBFS(TreeNode* root)
{
    vector<int> ans;

    if(root == NULL)return ans;

    //Approach: the very FIRST node at each LEVEL is what we need for the left view
    //T.C --> O(N), S.C --> O(Width) [for queue: max S.C will be the width of the tree. i.e. the max number of nodes present at a single level]
    //ignoring the S.C --> for vector<int> ans;
    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty())
    {
        int size = q.size();

        for(int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            if(i == 0)ans.push_back(node->val);

            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
    }

    return ans;
}

vector<int> rightViewOfBinaryTreeBFS(TreeNode* root)
{
    vector<int> ans;

    if(root == NULL)return ans;

    //Approach: the very LAST node at each LEVEL is what we need for the left view
    //T.C --> O(N), S.C --> O(Width) [for queue: max S.C will be the width of the tree. i.e. the max number of nodes present at a single level]
    //ignoring the S.C --> for vector<int> ans;
    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty())
    {
        int size = q.size();

        for(int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            if(i == size - 1)ans.push_back(node->val);

            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
    }

    return ans;
}

void leftViewDFS(TreeNode* root, int level, vector<int>&ans)
{
    //APPROACH: taking the Root->Right->Left approach to traverse the tree, just need to reverse the approach to Root->LEFT->Right in order to get the LEFT View of the tree
    //T.C --> O(N), S.C -->O(H) ~~ O(N)[in case of SKEWED Tree]

    if(root == NULL)return;

    //this makes sure we add the right most node to our ans 
    if(ans.size() == level)ans.push_back(root->val);

    //making the call to node->right first, so that we encounter the rightmost node on each successive level
    leftViewDFS(root->left, level + 1, ans);
    leftViewDFS(root->right, level + 1, ans);
}
vector<int> leftViewOfBinaryTreeDFS(TreeNode* root)
{
    vector<int>ans;
    if(root == NULL)return ans;
    leftViewDFS(root, 0, ans);
    return ans;
}


void rightViewDFS(TreeNode* root, int level, vector<int>&ans)
{
    //APPROACH: taking the Root->Right->Left approach to traverse the tree, just need to reverse the approach to Root->LEFT->Right in order to get the LEFT View of the tree
    //T.C --> O(N), S.C -->O(H) ~~ O(N)[in case of SKEWED Tree]

    if(root == NULL)return;

    //this makes sure we add the right most node to our ans 
    if(ans.size() == level)ans.push_back(root->val);

    //making the call to node->right first, so that we encounter the rightmost node on each successive level
    rightViewDFS(root->right, level + 1, ans);
    rightViewDFS(root->left, level + 1, ans);
}
vector<int> rightViewOfBinaryTreeDFS(TreeNode* root)
{
    vector<int>ans;
    if(root == NULL)return ans;
    rightViewDFS(root, 0, ans);
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

    vector<int> leftView = leftViewOfBinaryTreeBFS(root);
    printArray(leftView);
    vector<int> rightView = rightViewOfBinaryTreeBFS(root);
    printArray(rightView);
    /*Recursive Approach is better that BFS approach in terms of Space Complexity.
    As the worst case S.C for BFS --> O(Width), Worst S.C for DFS --> O(H) ~~ O(N) [When the TREE is SKEWED]
    But however for the majority of cases DFS would consume less space*/
    vector<int> leftViewDFS = leftViewOfBinaryTreeDFS(root);
    printArray(leftViewDFS);
    vector<int> rightViewDFS = rightViewOfBinaryTreeDFS(root);
    printArray(rightViewDFS);

    return 0;
}