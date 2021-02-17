int singleNumber(int* nums, int numsSize){
    int i=0; 
    int iRet=0;
    for(i=0;i<numsSize;i++)
    {
        iRet = iRet^nums[i];
    }
    return iRet;
}
