/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* searchBST(struct TreeNode* root, int val){
    struct TreeNode *localNode = root;
    while(localNode)
    {
        if(val == localNode->val)
        {
            return localNode;
        }
        else if(val < localNode->val)
        {
            localNode = localNode->left;
        }
        else
        {
            localNode = localNode->right;
        }
    }
    return localNode;
}
