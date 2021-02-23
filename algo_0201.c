int rangeBitwiseAnd(int m, int n){
    int iCounter=0;
    while(m!=n)
    {
        m=m>>1;
        n=n>>1;
        iCounter++;
    }
    m=m<<iCounter;
    return m;
}
