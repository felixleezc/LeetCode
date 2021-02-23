/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    struct TreeNode *lastNode = root;
    struct TreeNode *curNode = NULL;
    struct TreeNode *newNode = malloc(sizeof(struct TreeNode));
    memset(newNode,0,sizeof(struct TreeNode));
    newNode->val = val;
    if(lastNode)
    {
        if(lastNode->val > val)
        {
            curNode = lastNode->left;
        }
        else
        {
            curNode = lastNode->right;
        }
    }
    else
    {
        return newNode;
    }
    while(curNode)
    {
        lastNode = curNode;
        if(lastNode->val > val)
        {
            curNode = lastNode->left;
        }
        else
        {
            curNode = lastNode->right;
        }
    }
    if(lastNode->val > val)
    {
        lastNode->left = newNode;
    }
    else
    {
        lastNode->right = newNode;
    }
    return root;
}
