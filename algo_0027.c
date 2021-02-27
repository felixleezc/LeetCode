int removeElement(int* nums, int numsSize, int val){
    int iRetLen = 0;
    int i = 0;
    for(i = 0;i< numsSize;i++)
    {
        if(val != nums[i])
        {
            nums[iRetLen++] = nums[i];
        }
    }
    return iRetLen;
}
