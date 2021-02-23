/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* deleteNode(struct TreeNode* root, int key){
    struct TreeNode *targetNode = NULL;
    struct TreeNode *nextNode = NULL;
    struct TreeNode *parentOfTargNode = NULL;
    struct TreeNode *parentOfNextNode = NULL;
    struct TreeNode *localNode = root;
    struct TreeNode *pStack[2000];
    memset(pStack,0,2000*sizeof(struct TreeNode *));
    int i = -1;
    int j = -1;
    
    //进行中序遍历
    while(localNode||i>=0)
    {
        
        while(localNode)
        {
            pStack[++i] = localNode;
            localNode = localNode->left;
        }
        if(!localNode)
        {
            localNode = pStack[i--];
            if(key == localNode->val)
            {
                targetNode = localNode;
                /*if(-1 == i&&targetNode->right == NULL)
                {
                    nextNode = targetNode;
                    break;
                }*/
            }
            else if(targetNode)
            {
                //说明上一个节点已经找到，此时root为targetNode中序后继节点
                nextNode = localNode;
                break;
            }
            localNode = localNode->right;
        }
        
    }

    if(targetNode)
    {
        if(nextNode)
        {
            if(nextNode->left == targetNode)
            {
                nextNode->left=targetNode->left;
                free(targetNode);
            }
            else if(targetNode->right !=NULL)
            {
                // 有下一节点，找到下一节点父节点，父节点的左子节点置为下一节点的右子节点
                localNode = root;
                parentOfNextNode = NULL;
                while(localNode)
                {

                    if(localNode->val == nextNode->val)
                    {
                        break;
                    }
                    else if(localNode->val > nextNode->val)
                    {
                        parentOfNextNode = localNode;
                        localNode = localNode->left;
                    }else 
                    {
                        parentOfNextNode = localNode;
                        localNode = localNode->right;
                    }
                }
                targetNode->val = nextNode->val;
                if(targetNode->right !=nextNode)
                {
                    parentOfNextNode->left = nextNode->right;
                }
                else
                {
                    parentOfNextNode->right = nextNode->right;
                }
            }
            else
            {
                localNode = root;
                parentOfTargNode = NULL;
                while(localNode)
                {

                    if(localNode->val == targetNode->val)
                    {
                        break;
                    }
                    else if(localNode->val > targetNode->val)
                    {
                        parentOfTargNode = localNode;
                        localNode = localNode->left;
                    }else 
                    {
                        parentOfTargNode = localNode;
                        localNode = localNode->right;
                    }
                }
                parentOfTargNode->right = targetNode->left;
                
            }
        }
        else
        {
            // 没有下一节点，找到目标节点的父节点
            localNode = root;
            parentOfTargNode = NULL;
            while(localNode)
            {

                if(localNode->val == targetNode->val)
                {
                    break;
                }
                else if(localNode->val > targetNode->val)
                {
                    parentOfTargNode = localNode;
                    localNode = localNode->left;
                }else 
                {
                    parentOfTargNode = localNode;
                    localNode = localNode->right;
                }
            }
            if(parentOfTargNode)
            {
                parentOfTargNode->right = targetNode->left;
            }
            else
            {
                root=root->left;
            }
        }

           
    }
    //tmpNextNode->val = 999;
    return root;
}
