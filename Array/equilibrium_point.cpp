// https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1

//METHOD-1 0.29s
int equilibriumPoint(long long a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    int lsum = 0, rsum = sum;

    for (int i = 0; i < n; i++)
    {
        rsum -= a[i];
        if (rsum == lsum)
            return i + 1;
        lsum += a[i];
    }
    return -1;
}

//METHOD-2 0.31s
int equilibriumPoint(long long a[], int n)
{
    if (n == 1)
        return 1;
    int fwd[n], rev[n];
    fwd[0] = a[0], rev[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++)
        fwd[i] = fwd[i - 1] + a[i];
    for (int i = n - 2; i >= 0; i--)
        rev[i] = rev[i + 1] + a[i];

    for (int i = 0; i < n; i++)
    {
        if (fwd[i] == rev[i])
            return i + 1;
    }

    return -1;
}

//METHOD-3 0.31s
int equilibriumPoint(long long a[], int n)
{
    if (n == 1)
        return 1;
    int mid = n / 2;
    int lsum = 0, rsum = 0;
    for (int i = 0; i < mid; i++)
        lsum += a[i];
    for (int i = n - 1; i > mid; i--)
        rsum += a[i];
    if (rsum > lsum)
    {
        while (rsum > lsum && mid < n - 1)
        {
            rsum -= a[mid + 1];
            lsum += a[mid];
            mid++;
        }
    }
    else
    {
        while (rsum < lsum && mid > 0)
        {
            rsum += a[mid];
            lsum -= a[mid - 1];
            mid--;
        }
    }

    if (lsum == rsum)
        return mid + 1;
    else
        return -1;
}