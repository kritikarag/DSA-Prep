// https://leetcode.com/problems/number-of-pairs-satisfying-inequality/description/

Overall TC: O(N log^(2)N)
long long int count = 0;
void checkcount(vector<int> &vec, int start, int mid, int end, int d)
{
    int l = start, r = mid + 1;
    while (l <= mid && r <= end)
    {
        if (vec[l] <= vec[r] + d)
        {
            count += (end - r + 1);
            l++;
        }
        else
        {
            r++;
        }
    }
    // Double pointer approach can be used for decreasing TC
    sort(vec.begin() + start, vec.begin() + end + 1);
    return;
}

void mergesort(vector<int> &vec, int start, int end, int d)
{
    if (start == end)
        return;
    
    int mid = (start + end) / 2;
    
    mergesort(vec, start, mid, d);
    mergesort(vec, mid + 1, end, d);

    checkcount(vec, start, mid, end, d);
    return;
}

long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int d)
{
    int n = nums1.size();
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        c[i] = nums1[i] - nums2[i];
    mergesort(c, 0, n - 1, d);

    return count;
}