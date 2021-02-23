/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



bool isValidHelper(struct TreeNode* root, int *iPrev, int *iCounter)
{
    if(NULL == root)
    {
        return true;
    }
    if(!isValidHelper(root->left,iPrev,iCounter))
    {
        return false;
    }
    if(*iPrev >= root->val)
    {
        if((0 == *iCounter)&&(*iPrev == root->val)&&(*iPrev ==-2147483648))
        {
            *iCounter = *iCounter + 1;
        }
        else
        {
            return false;
        }
    }
    else
    {
        *iCounter = *iCounter + 1;
        *iPrev = root->val;
    }
    if(!isValidHelper(root->right,iPrev,iCounter))
    {
        return false;
    }
    return true;
}

bool isValidBST(struct TreeNode* root){
    int iPrev = -2147483648;
    int iCounter = 0;
    if(!root->left&&!root->right)
    {
        return true;
    }
    return isValidHelper(root, &iPrev,&iCounter);
}
