// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/

int pairSum(ListNode *head)
{
    ListNode *slowPtr = head;
    ListNode *fastPtr = head;
    ListNode *prevPtr = nullptr;

    while (fastPtr != nullptr && fastPtr->next != nullptr)
    {
        fastPtr = fastPtr->next->next;
        ListNode *nextNode = slowPtr->next;
        slowPtr->next = prevPtr;
        prevPtr = slowPtr;
        slowPtr = nextNode;
    }

    if (fastPtr != nullptr)
    {
        slowPtr = slowPtr->next;
    }

    int maxSum = std::numeric_limits<int>::min();
    while (slowPtr != nullptr)
    {
        maxSum = std::max(maxSum, slowPtr->val + prevPtr->val);
        slowPtr = slowPtr->next;
        prevPtr = prevPtr->next;
    }
    return maxSum;
}