// https://leetcode.com/problems/find-smallest-letter-greater-than-target/

char nextGreatestLetter(vector<char> &letters, char target)
{
    if (letters.back() <= target)
        return letters.front();
    char ans;
    int low = 0, high = letters.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (letters[mid] > target)
        {
            ans = letters[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

char nextGreatestLetter(vector<char> &letters, char target)
{
    int index = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
    return index >= letters.size() ? letters[0] : letters[index];
}