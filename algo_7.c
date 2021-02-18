int reverse(int x){
    int isNegetive = (x<0?1:0);
    int iArray[10];//32bit有符号整数最多为4294967296/2为10位数
    int iReverseLength = 0;
    if(-2147483648 == x)
    {
        return 0;
    }
    int iLocal = (x<0?(0-x):x);
    int i = 0, j = 0;
    int iRet = 0;
    memset(iArray,0,10*sizeof(int));
    while(0 != iLocal)
    {
        iArray[i++] =  iLocal%10;
        iLocal = iLocal/10;
    }
    for(j = i-1;j>=0;j--)
    {
        if(iArray[j])
        {
            break;
        }
    }
    iReverseLength = j+1;
    for(j = 0; j < iReverseLength; j++)
    {
        if(214748364 < iRet)
        {
            return 0;
        }
        iRet = iRet*10 + iArray[j];
    }
    if(iRet>>31)
    {
        //32bit最左边为1说明为负数了，说明超范围
        return 0;
    }
    else
    {
        return (isNegetive?(0-iRet):iRet);
    }

}
