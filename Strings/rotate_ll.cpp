// https://leetcode.com/problems/rotate-list/

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    ListNode *temp = head;
    int count = 1;
    while (temp->next)
    {
        count++;
        temp = temp->next;
    }
    temp->next = head;
    k = k % count;
    k = count - k;
    ListNode *temp2 = head;
    while (k--)
    {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}