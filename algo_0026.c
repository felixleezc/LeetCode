int removeDuplicates(int* nums, int numsSize){
    int i = 1;
    int iRetLen = 1;
    if(1 >= numsSize)
    {
        return numsSize;
    }
    for(i = 1; i < numsSize;i++)
    {
        if(nums[i] != nums[i-1])
        {
            nums[iRetLen++] = nums[i];
        }
    }
    return iRetLen;
}
