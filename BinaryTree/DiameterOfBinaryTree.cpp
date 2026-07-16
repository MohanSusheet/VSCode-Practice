#include<iostream>

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

int diameter = 0;

int diameterOfBinaryTreeOptimal(TreeNode* root)
{
    //T.C --> O(N)
    //S.C --> O(H) ~~ O(N) [worst case i.e. skewed Tree]  
    if(root == NULL)return 0;

    int lh = diameterOfBinaryTreeOptimal(root->left);
    int rh = diameterOfBinaryTreeOptimal(root->right);

    diameter = max(diameter, 1 + lh + rh);
    return 1 + max(lh, rh);
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
    // root->right->right->left = new TreeNode(13);


    /*
    DIAMETER of a Binary Tree: --> Longest path between any 2 nodes in the tree
                               --> Need not pass via the Root Node
    */

    //in Brute Force Approach: calculatuing leftHeight and rightHeight for every Node
    //T.C --> O(N^2)

    diameterOfBinaryTreeOptimal(root);

    cout<<"dia_in_terms_of_nodes: "<<diameter;

    //NOTE : diameter in terms of edges = dia_in_terms_of_nodes - 1

    return 0;
}