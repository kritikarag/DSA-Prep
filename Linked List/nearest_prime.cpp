// https://practice.geeksforgeeks.org/problems/6cb0782855c0f11445b8d70e220f888e6ea8e22a/1

bool prime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int nearestprime(int n)
{
    if (n == 1)
        return 2;
    if (prime(n))
        return n;

    int lp = n, rp = n;
    while (lp > 1 && rp < (n * n))
    {
        lp--;
        if (prime(lp))
            return lp;
        rp++;
        if (prime(rp))
            return rp;
    }
    return 0;
}
Node *primeList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        int num = temp->val;
        temp->val = nearestprime(num);
        temp = temp->next;
    }
    return head;
}