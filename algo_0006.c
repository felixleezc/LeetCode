char * convert(char * s, int numRows){
    char sRet[1000+1][1000+1];
    memset(sRet, 0, sizeof(sRet));
    int iLength = strlen(s);
    int i = 0;
    int j = 0;
    int m = 0;
    int iCol = 0;
    int iRow = 0;
    int iMaxCol = 0;
    char *sRetStr = malloc(1000+1);
    memset(sRetStr,0,(1000+1)*sizeof(char));
    if(1 == numRows)
    {
        return s;
    }
    iMaxCol = (numRows-1)*(iLength/(2*numRows-2) + 1);
    while(s[i]!= 0)
    {
        if(iCol%(numRows-1) == 0&&iRow<(numRows-1))
        {
            sRet[iRow++][iCol] = s[i++];
        }
        //else if(iCol%(numRows-1) == 0&&(iRow==numRows-1))
        //{
        //    sRet[iRow--][iCol++] = s[i++];
        //}
        else
        {
            sRet[iRow--][iCol++] = s[i++];
        }
    }

    for(i = 0; i < numRows;i++)
    {
        for(j = 0; j < iMaxCol; j++)
        {
            if(0 != sRet[i][j])
            {
                sRetStr[m++] = sRet[i][j];
            }
        }
    }
    return sRetStr;
}
