if (head == nullptr || head->next == nullptr) return head;

        ListNode* prev = head;
        Listnode* ptr = head->next;
        while (ptr != nullptr) {
            if (prev->val == ptr->val)
                prev->next = ptr->next;
            else
                prev = prev->next;

            ptr = ptr->next;
        }

        return head;
