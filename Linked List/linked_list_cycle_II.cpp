// https://leetcode.com/problems/linked-list-cycle-ii/description/

/*An easier formula to explain to the interviewer:

L1 is defined as the distance between the head point and entry point
L2 is defined as the distance between the entry point and the meeting point
x is defined as the remaining length of the cycle
Distance traveled by slow when they meet: L1+L2
Distance traveled by fast when they meet: L1+L2+x+L2,
where x is the remaining length of the cycle (meeting point to start of the cycle).

2(L1+L2) = L1+L2+x+L2
2L1 + 2L2 = L1+2L2+x
=> x = L1

so we need to move L1 steps from the current meeting point to reach the entry point of the cycle.*/

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