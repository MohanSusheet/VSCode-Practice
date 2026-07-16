#include<iostream>
#include<vector>
#include<stack>

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

vector<int> preorderTraversal(TreeNode* root) 
{
    //Iterative traversal using Stack
    //T.C --> O(N) [each node visited once], S.C --> O(max depth/height) + O(N)[ans array]

    if(root == NULL)return {};
    stack<TreeNode*> st;
    vector<int> preorder;

    st.push(root);

    while(!st.empty())
    {
        TreeNode* root = st.top();
        st.pop();

        preorder.push_back(root->val); //pushing the root val to ans array

        //pushing into the stack in reverse order RIGHT then LEFT, So at the time of printing ans -> LEFT is First OUT then RIGHT
        if(root->right != NULL)st.push(root->right);
        if(root->left != NULL)st.push(root->left);
    } 

    return preorder;
}

vector<int> inorderTraversal(TreeNode* root)
{
    //Iterative traversal using Stack
    //T.C --> O(N) [each node visited once], S.C -->O(N) ~~ O(max depth/height) + O(N)[ans array]

    if(root == NULL)return {};
    stack<TreeNode*> st;
    vector<int> inorder;
    TreeNode* node = root;

    while(true)
    {
        if(node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if(st.empty())break;
            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node = node->right;
        }
    }

    return inorder;
}

vector<int> postorderTraversal(TreeNode* root) 
{
    //Iterative traversal using 2 Stacks
    //T.C --> O(N) [each node visited once], S.C -->O(2N) ~~ O(max depth/height) + O(N)[ans array]

    if(root == NULL)return {};

    stack<TreeNode*> st1, st2;
    vector<int> postorder;

    st1.push(root);

    while(!st1.empty())
    {
        TreeNode* node = st1.top();
        st1.pop();
        st2.push(node);
        if(node->left != NULL)st1.push(node->left);
        if(node->right != NULL)st1.push(node->right);
    }

    while(!st2.empty())
    {
        TreeNode* node = st2.top();
        st2.pop();
        postorder.push_back(node->val);
    }

    return postorder;
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

    vector<int> preorder, inorder, postorder;

    preorder = preorderTraversal(root);
    printTraversalArray(preorder);

    inorder = inorderTraversal(root);
    printTraversalArray(inorder);

    postorder = postorderTraversal(root);
    printTraversalArray(postorder);

    return 0;
}