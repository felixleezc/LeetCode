int myAtoi(char * s){
    int iLength = strlen(s);
    int i = 0;
    int iArray[11];
    int j = 0, m =0;
    int iRet = 0;
    int isNegetive = 0;
    memset(iArray,0,10*sizeof(int));
    while(' ' == s[i])
    {
        i++;
    }
    if('-' == s[i])
    {
        isNegetive = 1;
        i++;
    }
    else if('+' == s[i])
    {
        i++;
    }
    while('0' == s[i])
    {
        i++;
    };
    while((i < iLength)&&(s[i] - 48 <= 9)&&(s[i] - 48 >= 0)&&j<11)
    {
        iArray[j++] = s[i++] - 48;
    }
    while(m < j&&m<9)
    {
        iRet = iRet*10 + iArray[m++];
    }

    if(10 == j)
    {
        if(214748364 < iRet)
        {
            return isNegetive?(-2147483648):2147483647;
        }
        else if(214748364 == iRet)
        {
            if((isNegetive&&iArray[j-1]<=8))
            {
                iRet = -iRet*10 - iArray[j-1];
                return iRet;
            }
            else if((!isNegetive && iArray[j-1]<=7))
            {
                return iRet*10 + iArray[j-1];
            }
            else
            {
                return isNegetive?(-2147483648):2147483647;
            }
        }
        else
        {
            iRet = iRet*10 + iArray[j-1];
            return isNegetive?(-iRet):iRet;
        }
    }
    else if(j > 10)
    {
        return isNegetive?(-2147483648):2147483647;
    }
    else
    {
        return isNegetive?(-iRet):iRet;
    }
}
