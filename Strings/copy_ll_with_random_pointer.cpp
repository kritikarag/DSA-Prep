// https://leetcode.com/problems/copy-list-with-random-pointer/

Node *copyRandomList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        Node *curr = new Node(temp->val);
        curr->next = temp->next;
        temp->next = curr;
        temp = temp->next->next;
    }

    temp = head;

    while (temp)
    {
        if (temp->random)
            temp->next->random = temp->random->next;
        temp = temp->next->next;
    }

    temp = head;
    Node *itr = new Node(0);
    Node *curr = itr, *front;

    while (temp)
    {
        // front = temp->next->next;
        curr->next = temp->next;
        temp->next = temp->next->next;
        curr = curr->next;
        temp = temp->next;
    }
    return itr->next;
}