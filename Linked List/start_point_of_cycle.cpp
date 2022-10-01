// https://leetcode.com/problems/linked-list-cycle-ii/

ListNode *detectCycle(ListNode *head)
{
    map<ListNode *, int> mp;
    while (head)
    {
        if (mp[head] > 0)
            return head;
        mp[head]++;
        head = head->next;
    }

    return NULL;
}

ListNode *detectCycle(ListNode *head)
{
    map<ListNode *, int> mp;
    while (head)
    {
        if (mp[head] > 0)
            return head;
        mp[head]++;
        head = head->next;
    }

    return NULL;
}