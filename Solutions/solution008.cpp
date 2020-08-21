#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* newNode(int data)
{
    TreeNode* newnode = new TreeNode;
    newnode->val = data;
    newnode->left = newnode->right = NULL;

    return newnode;
}

bool univalTreesHelper(TreeNode* root,int &univalTree)
{
    if(root == NULL)
    {
        return true;
    }

    bool left = univalTreesHelper(root->left, univalTree);
    bool right = univalTreesHelper(root->right, univalTree);

    if(left == false || right == false)
    {
        return false;
    }

    if(root->left != NULL && root->val != root->left->val)
    {
        return false;
    }

    if(root->right != NULL && root->val != root->right->val)
    {
        return false;
    }

    univalTree++;
    return true;
}

int univalTreesCount(TreeNode* root)
{
    int univalTree = 0;
    univalTreesHelper(root, univalTree);
    return univalTree;
}

int main()
{
/*

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1

*/
    TreeNode* root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(0);
    root->right->left = newNode(1);
    root->right->right = newNode(0);
    root->right->left->left = newNode(1);
    root->right->left->right = newNode(1);

    cout << univalTreesCount(root) << endl;
    return 0;
}