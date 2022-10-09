// https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1

void zigZag(int arr[], int n)
{
    // flag true mean '<' is expected otherwise '>' is expected
    bool flag = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (flag)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
        else
        {
            if (arr[i + 1] > arr[i])
            {
                swap(arr[i], arr[i + 1]);
            }
        }

        flag = !flag;
    }
}