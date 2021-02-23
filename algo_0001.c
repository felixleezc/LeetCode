/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* retArr=NULL;
    *returnSize = 0;
    int i = 0, j = 0;
    for(i = 0; i < numsSize-1; i++)
    {
        for(j = i+1; j < numsSize; j++)
        {
            if(target == nums[i]+nums[j])
            {
                retArr = (int *) malloc(2*sizeof(int));
                retArr[0] = i;
                retArr[1] = j;
                *returnSize = 2;
                break;
            }
        }
    }
    return retArr;
}
