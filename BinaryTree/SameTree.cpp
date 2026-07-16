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

bool isSameTree(TreeNode* p, TreeNode* q)
{
    //T.C --> O(N) [each node visited once]
    //S.C --> O(min(H1, H2))
    // if(p == NULL && q == NULL)return true;
    // if((p != NULL && q == NULL) || (p == NULL && q != NULL))return false;
    if(p == NULL || q == NULL)return p == q;

    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


int main()
{
    TreeNode* p = new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode* q = new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    // TreeNode* q = new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(8)));

    //as "<<" has greated precedence and gets exeuted before the ?: [ternary statement]. Hence, use of brackets is required in order to evaluate the ternary operation first
    cout<<"Are the 2 Trees p and q same? "<< (isSameTree(p, q)? "Yes": "No");

    return 0;
}