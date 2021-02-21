int climbStairs(int n){
    int iNMOne = 1;
    int iNMTwo = 1;
    int i = 0;
    int iSum = 0;
    if(n<=1)
    {
        return 1;
    }
    for(i = 2; i <= n; i++)
    {
        iSum = iNMOne + iNMTwo;
        iNMOne = iNMTwo;
        iNMTwo = iSum;
    }
    return iSum;
}
