int findMaxConsecutiveOnes(int* nums, int numsSize){
    int i = 0;
    int iMaxOneNum = 0;
    int iTmpMaxOneNum = 0;
    while (i<numsSize)
    {
        if(nums[i])
        {
            iTmpMaxOneNum++;
        }
        else
        {
            if(iTmpMaxOneNum>iMaxOneNum)
            {
                iMaxOneNum = iTmpMaxOneNum;
            }
            iTmpMaxOneNum = 0;
        }
        i++;
    }
    if(iTmpMaxOneNum>iMaxOneNum)
    {
        iMaxOneNum = iTmpMaxOneNum;
    }
    return iMaxOneNum;
}
