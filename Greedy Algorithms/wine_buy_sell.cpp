// https://practice.geeksforgeeks.org/problems/wine-buying-and-selling/1

long long int wineSelling(vector<int> &arr, int n)
{
    // Code here.
    long long ans = 0;
    int buy = 0, sell = 0;
    while (buy < n && sell < n)
    {
        while (arr[buy] <= 0 && buy < n)
            buy++;
        while (arr[sell] >= 0 && sell < n)
            sell++;
        if (arr[buy] > 0 && arr[sell] < 0)
        {
            int diff = abs(sell - buy);
            if (abs(arr[buy]) <= abs(arr[sell]))
            {

                ans += diff * arr[buy];
                arr[sell] += arr[buy];
                arr[buy] = 0;
            }
            else
            {
                ans += diff * abs(arr[sell]);
                arr[buy] += arr[sell];
                arr[sell] = 0;
            }
        }
        else
        {
            return ans;
        }
    }
    return ans;
}