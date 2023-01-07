//


Recursive Approach:
Node *merge(Node *n1, Node *n2)
{
    Node *temp = new Node(0);
    Node *res = temp;

    while (n1 && n2)
    {
        if (n1->data <= n2->data)
        {
            temp->bottom = n1;
            temp = temp->bottom;
            n1 = n1->bottom;
        }
        else
        {
            temp->bottom = n2;
            temp = temp->bottom;
            n2 = n2->bottom;
        }
    }
    if (n1)
    {
        temp->bottom = n1;
    }
    else
    {
        temp->bottom = n2;
    }
    return res->bottom;
}
Node *flatten(Node *root)
{
    // Your code here
    if (!root || !root->next)
    {
        return root;
    }

    root->next = flatten(root->next);
    root = merge(root, root->next);

    return root;
}

Priority Queue: