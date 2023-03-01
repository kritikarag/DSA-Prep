void heapify(vector<int> &vec, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && vec[l] > vec[largest])
        largest = l;
    if (r < n && vec[r] > vec[largest])
        largest = r;

    if (vec[largest] != vec[i])
    {
        swap(vec[i], vec[largest]);

        heapify(vec, n, largest);
    }
}
void heapsort(vector<int> &vec, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(vec, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}
vector<int> sortArray(vector<int> &nums)
{
    heapsort(nums, nums.size());

    return nums;
}