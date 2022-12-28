// https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/?envType=study-plan&id=data-structure-ii

int findTheWinner(int n, int k)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    int count = 1;
    while (q.size() > 1)
    {
        if (count == k)
        {
            q.pop();
            count = 1;
        }
        else
        {
            q.push(q.front());
            q.pop();
            count++;
        }
    }
    return q.front();
}