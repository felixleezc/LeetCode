/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* averageOfLevels(struct TreeNode* root, int* returnSize){
    struct TreeNode *pRetArray[100000] = {0};
    //memset(pRetArray,0,sizeof(pRetArray));
    int iHead = 0;
    int iTail = 0;
    int j;
    int iLevelNum[100000]; //最大1000层,记录每层节点数
    int iLevelCount = 0; //记录总层数
    double dSumArray[100000]; //每层val和
    memset(iLevelNum,0,100000*sizeof(int)); //不初始化会出错
    memset(dSumArray,0,100000*sizeof(double)); //不初始化会出错
    pRetArray[0] = root;
    if(!pRetArray[0])
    {
        *returnSize = 0;
        return NULL;
    }
    iTail++;
    iLevelNum[0] = 1; //第一层有一个节点(根节点))

    while(iHead < iTail)
    {
        iLevelCount++;
        int i = 0;
        for(i=0; i < iLevelNum[iLevelCount-1]; i++)
        {
            /* 将子节点加到队列 */
            if(!pRetArray[iHead])
            {
                double *dRetArray = malloc(5*sizeof(double));
                *returnSize = 5;
                dRetArray[0] = iHead;
                dRetArray[1] = iTail;
                dRetArray[2] = iLevelCount;
                dRetArray[3] = iLevelNum[iLevelCount-1];
                dRetArray[4] = i;

                return dRetArray;
            }
            if(pRetArray[iHead]->left)
            {
                pRetArray[iTail] = pRetArray[iHead]->left;
                iTail++;
                iLevelNum[iLevelCount] = iLevelNum[iLevelCount] + 1;
            }
            if(pRetArray[iHead]->right)
            {
                pRetArray[iTail] = pRetArray[iHead]->right;
                iTail++;
                iLevelNum[iLevelCount] = iLevelNum[iLevelCount] + 1;
            }
            /* 将本层节点进行求和 */
            dSumArray[iLevelCount - 1] += pRetArray[iHead]->val;
            /*每次处理完成之后队列头要压出*/
            iHead++;
        }
    }
    double *dRetArray = malloc(iLevelCount*sizeof(double));
    for(j = 0;j<iLevelCount;j++)
    {
        dRetArray[j] = dSumArray[j]/iLevelNum[j];
    }
    *returnSize = iLevelCount;
    return dRetArray;
}
