// https://practice.geeksforgeeks.org/problems/black-and-white-1587115620/1

long long numOfWays(int N, int M)
{
    // write code here
    long long int sum = 0;

    int mod = 1e9 + 7;

    for (int i = 0; i < N; i++)

    {
        for (int j = 0; j < M; j++)
        {
            long long int cnt = 1;

            if (i - 2 >= 0 && j + 1 >= 0 && i - 2 < N && j + 1 < M)
                cnt++;

            if (i - 2 >= 0 && j - 1 >= 0 && i - 2 < N && j - 1 < M)
                cnt++;

            if (i - 1 >= 0 && j + 2 >= 0 && i - 1 < N && j + 2 < M)
                cnt++;

            if (i - 1 >= 0 && j - 2 >= 0 && i - 1 < N && j - 2 < M)
                cnt++;

            if (i + 2 >= 0 && j - 1 >= 0 && i + 2 < N && j - 1 < M)
                cnt++;

            if (i + 2 >= 0 && j + 1 >= 0 && i + 2 < N && j + 1 < M)
                cnt++;

            if (i + 1 >= 0 && j + 2 >= 0 && i + 1 < N && j + 2 < M)
                cnt++;

            if (i + 1 >= 0 && j - 2 >= 0 && i + 1 < N && j - 2 < M)
                cnt++;

            sum = sum + (N * M - cnt);
        }
    }
    return sum % mod;
}