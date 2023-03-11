// https://practice.geeksforgeeks.org/problems/d54c71dc974b7db3a200eb63f34e3d1cba955d86/1

long long maxTripletProduct(long long arr[], int n)
{
    
    long long mini1 = INT_MAX, mini2 = INT_MAX, maxi1 = INT_MIN, maxi2 = INT_MIN, maxi3 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < mini1)
        {
            mini2 = mini1;
            mini1 = arr[i];
        }
        else if (arr[i] < mini2)
        {
            mini2 = arr[i];
        }
        if (arr[i] > maxi1)
        {
            maxi3 = maxi2;
            maxi2 = maxi1;
            maxi1 = arr[i];
        }
        else if (maxi2 < arr[i])
        {
            maxi3 = maxi2;
            maxi2 = arr[i];
        }
        else if (maxi3 < arr[i])
        {
            maxi3 = arr[i];
        }
    }

    // cout<<mini1<<" "<<mini2<<" "<<maxi1<<" "<<maxi2<<" "<<maxi3;
    long long prd1 = mini1 * mini2 * maxi1;
    long long prd2 = maxi1 * maxi2 * maxi3;

    return max(prd1, prd2);
}