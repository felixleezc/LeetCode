int pivotIndex(int* nums, int numsSize){
    int iSumLeft = 0;
    int iSumRight = 0;
    int i = 0;
    int m=0,n=0;
    for(i = 1; i < numsSize; i++)
    {
        iSumRight+=nums[i];
    }
    
    if(1 == numsSize||iSumRight == iSumLeft)
    {
        return 0;
    }
    if(0 == numsSize)
    {
        return -1;
    }
    i = 1;
    while(i < numsSize)
    {
        iSumRight -= nums[i];
        iSumLeft += nums[i - 1];
        
        //比较是否相等
        if(iSumLeft == iSumRight)
        {
            return i;
        }

        i++;
    }
    return -1;
}
