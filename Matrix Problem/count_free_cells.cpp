// https://practice.geeksforgeeks.org/problems/90a81c305b1fe939b9230a67824749ceaa493eab/1

vector<long long int> countZero(int n, int k, vector<vector<int>> &arr)
{
    // Code Here
    vector<long long int> ans;
    unordered_map<int, int> r, c;
    int rowc = 0;
    int colc = 0;
    for (int i = 0; i < k; ++i)
    {
        int x = arr[i][0];
        int y = arr[i][1];
        if (r.find(x) == r.end())
        {
            ++r[x];
            ++rowc;
        }

        if (c.find(y) == c.end())
        {
            ++c[y];
            ++colc;
        }

        long long int a = n * n - ((rowc + colc) * n) + (rowc * colc);
        ans.push_back(a);
    }
    return ans;
}