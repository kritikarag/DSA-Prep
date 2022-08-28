int isprime(int n)
{
    if (n <= 2 || n % 2 == 0)
        return 0;
    for (int i = 3; i <= n / i; i += 2)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int nearestprime(int n){
    if (isprime(n))
    {
         return n
    }
    if (n <= 2)
    {
        return 2;
    }
    int n1 = 0, n2 = 0, d1 = 0, d2 = 0,val;
    for (int i = n;; i++)
    {
        if (isprime(i))
        {
            d1 = i - n;
            n1 = i;
            break;
        }
    }
    for (int i = n;; i--)
    {
        if (isprime(i))
        {
            d2 = n - i;
            n2 = i;
            break;
        }
    }
    if (d1 < d2)
        val = n1;
    else
        val = n2;

    return val;
}