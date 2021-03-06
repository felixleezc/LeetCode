/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    int i = 0,j = 0,top = -1;
    if(0 == numsSize)
    {
        *returnSize = 0;
        return NULL;
    }
    int *pRetArray = malloc(numsSize*sizeof(int));
    int *pTmpStack = malloc((2*numsSize-1)*sizeof(int));
    memset(pRetArray,-1,numsSize*sizeof(int));
    memset(pTmpStack,0,(2*numsSize-1)*sizeof(int));
    for(i = 0; i < 2*numsSize -1;i++)
    {
        // 方法一
        // j = 0;
        // while(j < numsSize)
        // {
        //     if(nums[(i+j)%numsSize] > nums[i])
        //     {
        //         pRetArray[i] = nums[(i+j)%numsSize];
        //         break;
        //     }
        //     j++;
        // }

        //方法2
        if(0 <= top&&nums[pTmpStack[top]] < nums[i%numsSize])
        {
            while((0 <= top)&&nums[pTmpStack[top]] <nums[i%numsSize] )
            {
                pRetArray[pTmpStack[top]] = nums[i%numsSize];
                top--;
            }
        }
        pTmpStack[++top] = i%numsSize;

    }
    free(pTmpStack);
    *returnSize = numsSize;
    return pRetArray;
}
