int XOR_Numbers(int n)
{
    if (n % 4 == 0)
        return n;
    else if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}
int range(int l, int r){
    int total = XOR_Numbers(r);
    int prev = XOR_Numbers(l-1);
    return total ^ prev; 
}