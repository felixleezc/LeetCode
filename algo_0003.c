int lengthOfLongestSubstring(char * s){
    int testArray[127+1];
    int iTmpSize = 0;
    int iPreviousAnchor = 0;
    int iLongestSize = 0;
    int i = 0;
    memset(testArray,-1,sizeof(testArray));
    for(i = 0; i < strlen(s);i++)
    {
        while(0 > testArray[(int)s[i]]&&i < strlen(s))
        {
            testArray[s[i]] = i;
            iTmpSize++;
            i++;
        }
        if(iTmpSize > iLongestSize)
        {
            iLongestSize = iTmpSize;
        }
        if(i < strlen(s))
        {
            iPreviousAnchor = testArray[s[i]];
            memset(testArray,-1,sizeof(testArray));
            iTmpSize = 0;
            i = iPreviousAnchor;
        }
    }
    
    return iLongestSize;
}
