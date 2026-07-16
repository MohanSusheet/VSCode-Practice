#include<iostream>
#include<vector>
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

void printTraversalArray(vector<int>arr)
{
    for(int i: arr)cout<<i<<" ";
    cout<<endl;
}

void preorderTraversal(TreeNode* root, vector<int>&preorder)
{
    if(root == NULL)return;

    preorder.push_back(root->val);

    preorderTraversal(root->left, preorder);
    preorderTraversal(root->right, preorder);
}

void inorderTraversal(TreeNode* root, vector<int>&inorder)
{
    if(root == NULL)return;

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right, inorder);
}

void postorderTraversal(TreeNode* root, vector<int>&postorder)
{
    if(root == NULL)return;

    postorderTraversal(root->left, postorder);
    postorderTraversal(root->right, postorder);
    postorder.push_back(root->val);
}

void preorderTraversalIterative(TreeNode* root, vector<int>&preorder)
{

}

void inorderTraversalIterative(TreeNode* root, vector<int>&inorder)
{
    
}

void postorderTraversalIterative(TreeNode* root, vector<int>&postorder)
{
    
}


int main()
{
    // TreeNode* root = new TreeNode(8, new TreeNode(6, new TreeNode(4, new TreeNode(2), new TreeNode(5)), new TreeNode(7)), new TreeNode());
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


    vector<int> preorder, inorder, postorder;

    preorderTraversal(root, preorder);
    inorderTraversal(root, inorder);
    postorderTraversal(root, postorder);
    
    printTraversalArray(preorder);
    printTraversalArray(inorder);
    printTraversalArray(postorder);

    preorderTraversalIterative(root, preorder);
    inorderTraversalIterative(root, inorder);
    postorderTraversalIterative(root, postorder);


    return 0;
}