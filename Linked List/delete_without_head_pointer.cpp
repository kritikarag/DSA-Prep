void deleteNode(Node *del)
    {
        del->data = del->next->data;
        Node* temp1 = del->next;
        Node* temp2 = del->next->next;
    
        delete(temp1);
        del->next=temp2;
    }
