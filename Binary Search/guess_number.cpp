// https://leetcode.com/problems/guess-number-higher-or-lower/

int guessNumber(int n)
{
    int low = 1, high = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int curr = guess(mid);//Here guess function is auto provided api to give response to your pick

        if (curr == 0)
            return mid;

        else if (curr == -1)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}