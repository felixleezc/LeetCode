int strStr(char * haystack, char * needle){
    int iNeeLen = strlen(needle);
    int iHayLen = strlen(haystack);
    int i = 0,j=0;
    int iIndex = -1;
    if(0 == iNeeLen)
    {
        return 0;
    }
    for(i = 0;i < iHayLen; i++)
    {
        j = 0;
        while(j<iNeeLen&&needle[j] == haystack[i+j]&&(i+j)<iHayLen)
        {
            j++;
        }
        if(j==iNeeLen)
        {
            iIndex = i;
        }
        if(iIndex > -1)
        {
            break;
        }
    }
    return iIndex;

}
