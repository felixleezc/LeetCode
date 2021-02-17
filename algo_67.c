char * addBinary(char * a, char * b){
    int iLengthOfa = strlen(a);
    int iLengthOfb = strlen(b);
    int iCarry = 0;
    int iIndexOfa = iLengthOfa;
    int iIndexOfb = iLengthOfb;
    int iMax = (iIndexOfa>iIndexOfb?iIndexOfa:iIndexOfb)+1;//?:必须加（），不然最后iIndexOfb+1会当做整体
    char *sRet = malloc((iMax+1)*sizeof(char)); 
    memset(sRet,0,(iMax+1)*sizeof(char));
    while(iIndexOfa>0||iIndexOfb>0||iCarry>0)
    {
        sRet[iMax-1] = ((iIndexOfa >0?(a[iIndexOfa-1]-48):0) + (iIndexOfb >0?(b[iIndexOfb-1]-48):0) + iCarry)%2 + 48;
        iCarry = ((iIndexOfa >0?(a[iIndexOfa-1]-48):0) + (iIndexOfb >0?(b[iIndexOfb-1]-48):0) + iCarry)/2;
        iMax--;
        if(iIndexOfa>0)
        {
            iIndexOfa--;
        }
        if(iIndexOfb>0)
        {
            iIndexOfb--;
        }
    }
    if(iMax)
    {
        return (sRet+1);
    }
    else
    {
        return sRet;
    }
}
