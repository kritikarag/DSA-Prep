// https://leetcode.com/problems/check-if-n-and-its-double-exist/

bool checkIfExist(vector<int> &arr)
{
    unordered_set<int> set;
    for (int i : arr)
    {
        if (set.find(2 * i) != set.end() || i % 2 == 0 && set.find(i / 2) != set.end())
            return true;
        set.insert(i);
    }
    return false;
}