vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{ 
    vector<pair<int, int>> res;
    Node *end = head;
    while (end->next)
    {
        end = end->next;
    }

    while (end->data > head->data)
    {
        int sum = head->data + end->data;
        if (sum == target)
        {
            res.push_back(make_pair(head->data, end->data));
            head = head->next;
            end = end->prev;
        }
        else if (sum > target)
            end = end->prev;
        else
            head = head->next;
    }

    return res;
}