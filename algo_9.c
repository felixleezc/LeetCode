bool isPalindrome(int x){
    int iLength = 0;
    int iArray[10];
    int iTmpX = x;
    int i = 0,j=0;
    memset(iArray, 0, sizeof(iArray));
    if(x < 0)
    {
        return false;
    }
    while(iTmpX > 0)
    {
        iArray[iLength++] = iTmpX%10;
        iTmpX = iTmpX/10;
    }
    j = iLength-1;
    while(i < j)
    {
        if(iArray[i] != iArray[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
