

int search(int* nums, int numsSize, int target){
    int iStart= 0;
    int iEnd=numsSize -1;
    while(iStart!=iEnd)
    {
        if(iStart == iEnd - 1)
        {
            if(target == nums[iStart])
            {
                return iStart;
            }
            else if(target == nums[iEnd])
            {
                return iEnd;
            }
            else
            {
                return -1;
            }
        }
        if(nums[(iStart+iEnd)/2] == target)
        {
            return (iStart+iEnd)/2;
        }
        else if(nums[(iStart+iEnd)/2] < target)
        {
            iStart = (iStart+iEnd)/2;
        }
        else
        {
            iEnd = (iStart+iEnd)/2;
        }
    }
    return target==nums[iStart]?iStart:-1;
}
