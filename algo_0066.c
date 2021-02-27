/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *iArray = malloc((digitsSize+1)*sizeof(int));
    int i = digitsSize,j=0;
    int iCarry = 1;
    int iRetLen = 0;
    memset(iArray,0,(digitsSize+1)*sizeof(int));
    if(iCarry+digits[digitsSize-1] < 10)
    {
        digits[digitsSize-1]+=iCarry;
        *returnSize = digitsSize;
        return digits;
    }
    while(0 < i||iCarry>0)
    {
        if(0 < i)
        {
            iArray[i] = (digits[i-1] + iCarry)%10;
            iCarry = (digits[i-1] + iCarry)/10;
            i--;
        }
        else
        {
            iArray[i] = iCarry;
            iCarry = 0;
        }
        iRetLen++;
    } 
    if(iRetLen==digitsSize)
    {
        int *iRetArray = malloc(digitsSize*sizeof(int));
        memset(iRetArray,0,digitsSize*sizeof(int));
        memcpy(iRetArray,iArray+1,digitsSize*sizeof(int));
        free(iArray);
        *returnSize = iRetLen;
        return iRetArray;
    }
    else
    {
        *returnSize = iRetLen;
        return iArray;
    }

}
