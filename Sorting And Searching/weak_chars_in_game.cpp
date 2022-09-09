// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/

static bool compare(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] >= b[1];
    else
        return a[0] < b[0];
}
int numberOfWeakCharacters(vector<vector<int>> &prop)
{
    int ans = 0;
    //Sort the elements in ascending order on the basis of first in pair 
    //and if the first elements are equal and sort in descending order on the basis of second in pair
    sort(prop.begin(), prop.end(), compare);
    int maxi = INT_MIN;
    int n = prop.size();
    for (int it = n - 1; it >= 0; it--)
    {
        if (maxi > prop[it][1])
            ans++;
        else
            maxi = prop[it][1];
    }

    return ans;
}