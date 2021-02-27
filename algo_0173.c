/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



typedef struct {
    int top;
    int down;
    struct TreeNode *treeArray[30000];
} BSTIterator;


BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    struct TreeNode* pPointers[30000];
    BSTIterator* it = malloc(sizeof(BSTIterator));
    memset(it, 0, sizeof(BSTIterator));
    memset(pPointers,0,30000*sizeof(struct TreeNode*));
    int i = -1;
    while(root!=NULL||i > -1)
    {
        if(root!=NULL)
        {
            pPointers[++i] = root;
            root = root->left;
        }
        else if(NULL == root)
        {
            root = pPointers[i--];
            it->treeArray[it->top++] = root;
            root = root->right;
        }
    }
    return it;

}

int bSTIteratorNext(BSTIterator* obj) {
    if(!obj||obj->top < 1)
    {
        return 0;
    }
    if(obj->down + 1 > obj->top)
    {
        return 0;
    }
    return obj->treeArray[obj->down++]->val;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    if(!obj)
    {
        return NULL;
    }
    else
    {
        return obj->down <= obj->top-1;
    }
}

void bSTIteratorFree(BSTIterator* obj) {
    if(!obj)
    {
        return;
    }
    free(obj);    
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/
