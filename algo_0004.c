double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int iNums1Index = 0;
    int iNums2Index = 0;
    int iMidPosition = (nums1Size + nums2Size)>>1;
    int iSingleMid = 1; //是否只有一个中位数
    double dMidNum1 = 0-1000000,dMidNum2 = 0-1000000;
    int iTmpNum;
    if((nums1Size + nums2Size)%2 == 0)
    {
        iSingleMid = 0;     //此时中位数在两个数之间   
    }
    while((iNums1Index + iNums2Index) < iMidPosition + 1)
    {
        dMidNum1 = dMidNum2;
        iTmpNum = dMidNum2;
        if(iNums1Index < nums1Size && iNums2Index < nums2Size)
        {
            if(nums1[iNums1Index] <= nums2[iNums2Index] && iTmpNum <= nums1[iNums1Index])
            {
                dMidNum2 = nums1[iNums1Index];
                iNums1Index++;
                
            }
            else  if(nums1[iNums1Index] <= nums2[iNums2Index] && iTmpNum > nums1[iNums1Index])
            {
                dMidNum2 = nums2[iNums2Index];
                iNums2Index++;
                
            }
            else
            {
                if(iTmpNum <= nums2[iNums2Index])
                {
                    dMidNum2 = nums2[iNums2Index];
                    iNums2Index++;
                    
                }
                else
                {
                    dMidNum2 = nums1[iNums1Index];
                    iNums1Index++;
                    
                }
            }        
        }
        else
        {
            if(iNums1Index == nums1Size)
            {
                dMidNum2 = nums2[iNums2Index];
                iNums2Index++;
            }
            else
            {
                dMidNum2 = nums1[iNums1Index];
                iNums1Index++;
            }
        }
    }
    if(iSingleMid)
    {
        return dMidNum2;
    }
    else
    {
        return (dMidNum1 + dMidNum2)/2;
    }
}
