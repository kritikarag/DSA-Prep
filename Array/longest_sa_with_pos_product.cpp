// https://practice.geeksforgeeks.org/problems/4dfa8ba14d4c94f4d7637b6b5246782412f3aeb8/1

int maxLength(vector<int> &arr, int n)
{
    int ans = 0, negcount = 0, prevzero = -1, firstneg = -1;
    for (int i = 0; i < n; i++)
    {
        //If we encounter a negative integer then we'll increment the count of negatives encountered till now
        if (arr[i] < 0)
        {
            negcount++;
            //In case first negative has been encountered then we will record it
            if (firstneg == -1)
            {
                firstneg = i;
            }
        }
        // If we encounter a zero then we would reset our values up until now
        if (arr[i] == 0)
        {
            firstneg = -1;
            negcount = 0;
            prevzero = i;
        }
        else
        {
            /*If the number of negative integers encountered till now is even,
            /then we'll consider the whole length from the last zero encountered up till the current index*/
            if (negcount % 2 == 0)
            {
                ans = max(ans, i - prevzero);
            }
            /*Else we'll consider the length from the first negative encountered till the current index*/
            else
            {
                ans = max(ans, i - firstneg);
            }
        }
    }
    return ans;
}