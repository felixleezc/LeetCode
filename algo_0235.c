/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    int iMaxLeft = 0;
    int iMaxRight = 0;
    if(!root)
    {
        return 0;
    }
    iMaxLeft = maxDepth(root->left);
    iMaxRight = maxDepth(root->right);
    return (iMaxLeft>iMaxRight?iMaxLeft:iMaxRight) + 1;
}
