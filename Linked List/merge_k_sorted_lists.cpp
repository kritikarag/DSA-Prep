// https://leetcode.com/problems/merge-k-sorted-lists/description/

struct compare
{
    bool operator()(const ListNode *l1, const ListNode *l2)
    {
        return l1->val > l2->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *temp = new ListNode(0);
    ListNode *node = temp;

    priority_queue<ListNode *, vector<ListNode *>, compare> pq;
    for (auto it : lists)
    {
        if (it)
            pq.push(it);
    }
    while (!pq.empty())
    {
        ListNode *top = pq.top();
        pq.pop();
        node->next = top;
        node = node->next;
        if (top->next)
        {
            pq.push(top->next);
        }
    }
    return temp->next;
}
