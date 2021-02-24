typedef struct node{
    int val;
    int childNum;
    int order;
    struct node *left;
    struct node *right;
} KthLargest, *pKthLargest;

//typedef SKthLargest *KthLargest; //定义二叉树，本质是结构体指针或节点指针

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    int i = 0;
    KthLargest *root = NULL;
    KthLargest *localNode = NULL;
    KthLargest *localParentNode = NULL;
    root = malloc(sizeof(KthLargest));
    memset(root,0,sizeof(KthLargest));
    root->order = k;
    if(numsSize > 0)
    {
        localNode = malloc(sizeof(KthLargest));
        localNode->val = nums[0];
        localNode->childNum = 1;
        localNode->order = k;
        localNode->left = NULL;
        localNode->right = NULL;
    }
    root->left = localNode;
    for(i = 1; i<numsSize; i++)
    {
        localNode = root->left;
        localParentNode = NULL;
        while(localNode)
        {
            localNode->childNum++;
            localParentNode = localNode;
            if(localNode->val > nums[i])
            {
                localNode = localNode->left;
            }
            else
            {
                localNode = localNode->right;
            }
        }
        localNode = malloc(sizeof(KthLargest));
        localNode->val = nums[i];
        localNode->childNum = 1;
        localNode->order = k;
        localNode->left = NULL;
        localNode->right = NULL;
        if(localParentNode->val > localNode->val)
        {
            localParentNode->left = localNode;
        }
        else
        {
            localParentNode->right = localNode;
        }
    }
    return root;
}

int kthLargestAdd(KthLargest* obj, int val) {
    KthLargest *objParent = NULL;
    KthLargest *root= obj->left;
     KthLargest *begin = NULL;
    int localk = obj->order;
    
    while(root)
    {
        objParent = root;
        root->childNum++;
        if(root->val <= val)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    root = malloc(sizeof(KthLargest));
    root->val = val;
    root->childNum = 1;
    root->order = obj->order;
    root->left = NULL;
    root->right = NULL;
    if(objParent)
    {
        if(objParent->val > root->val)
        {
            objParent->left = root;
        }
        else
        {
            objParent->right = root;
        }
    }
    else
    {
        obj->left = root;
    }
    begin = obj->left;
    // 寻找kth大number
    while(begin)
    {
        if(begin->right)
        {
            if(begin->right->childNum >= localk)
            {
                begin = begin->right;
            }
            else
            {
                localk = localk - begin->right->childNum - 1;
                if(0 == localk)
                {
                    return begin->val;
                }
                else
                {
                    begin = begin->left;
                }
            }
        }
        else
        {
            if(1 == localk)
            {
                return begin->val;
            }
            else
            {
                localk--;
                begin = begin->left;
            }
        }
    }
    return 0;
}

void kthLargestFree(KthLargest* obj) {
    KthLargest *objStack[10000];
    memset(objStack,0,10000*sizeof(KthLargest *));
    KthLargest *tmpObj = NULL;
    int i = -1;
    while(obj||i >= 0)
    {
        if(obj)
        {
            objStack[++i] = obj;
            obj = obj->left;
        }
        else
        {
            obj = objStack[i--];
            tmpObj = obj;
            obj = obj->right;
            free(tmpObj);
        }
    }
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/
