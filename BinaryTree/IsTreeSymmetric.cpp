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

bool checkSymmetry(TreeNode* p, TreeNode* q)
{
    if(p == NULL || q == NULL)return p == q;

    return p->val == q->val && (checkSymmetry(p->left, q->right)) && (checkSymmetry(p->right, q->left));
}
bool isSymmetric(TreeNode* root) 
{
    //Approach: Converting the problem into comparing 2 trees, whether they are the mirror images of one another. Using simple Recursive PreOrder Traversl
    
    //T.C -->O(N) traversing all the nodes && S.C --> O(H) 

    return root == NULL  || checkSymmetry(root->left, root->right) ;
}

int main()
{
    TreeNode* root = new TreeNode(10, new TreeNode(8, new TreeNode(5), new TreeNode(2)), new TreeNode(8, new TreeNode(2), new TreeNode(5)));

    cout<<isSymmetric(root);

    return 0;
}