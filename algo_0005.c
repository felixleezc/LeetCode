char * longestPalindrome(char * s){
    int iSize = strlen(s);
    
    int i = 0, j=0;
    int iLengthForMax = 0;
    int iIndexForMax = 0;
    int iTmpLengthForMax = 0;
    for (i = 0; i < 2*iSize - 1; i++ )
    {
        if(1 == i%2)
        {
            // 该位置为两个字符之间
            iTmpLengthForMax = 0;
            j = 0;
            while((i/2 - j) >= 0 && (i/2 + j+1) < iSize)
            {
                if(s[i/2 - j ] == s[i/2 + j + 1])
                {
                    iTmpLengthForMax = iTmpLengthForMax + 2;
                    j++;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            // 该位置为一个字符
            iTmpLengthForMax = 1;
            j = 1;
            while((i/2 - j)>=0&&(i/2 + j)<iSize)
            {
                if(s[i/2 - j] == s[i/2 + j])
                {
                    iTmpLengthForMax = iTmpLengthForMax + 2;
                    j++;
                }
                else
                {
                    break;
                }
            }
        }
        if(iTmpLengthForMax > iLengthForMax)
        {
            iLengthForMax = iTmpLengthForMax;
            iIndexForMax = i;
        }
    }
    char *sRet = malloc(iLengthForMax + 1);
    memset(sRet,0,(iLengthForMax+1)*sizeof(char));
    strncpy(sRet,(s+(iIndexForMax/2 - iLengthForMax/2 + iIndexForMax%2)),iLengthForMax);
    return sRet;
}
