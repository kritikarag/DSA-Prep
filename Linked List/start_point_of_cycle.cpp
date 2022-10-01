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

// Space Optimized Approach
ListNode *detectCycle(ListNode *head)
{
    ListNode *fast = head, *slow = head, *entry = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            while (entry != slow)
            {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
    }
    return NULL;
}