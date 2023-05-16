// https://leetcode.com/problems/swap-nodes-in-pairs/description/

ListNode *swapPairs(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *new_head = new ListNode(0);
    new_head->next = head;
    while (head && head->next)
    {
        int temp = head->val;
        head->val = head->next->val;
        head->next->val = temp;
        head = head->next->next;
    }

    return new_head->next;
}