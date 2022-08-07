int minimumNumbers(int num, int k)
{
    if (num == 0)
        return 0;
    if (num < k)
    {
        return -1;
    }
    for (int i = 1; i <= 10; i++)
    {
        if ((k * i) % 10 == num % 10)
        {
            if (k * i <= num)
            {
                return i;
            }
        }
    }
    return -1;
}