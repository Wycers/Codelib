class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *res = head, *a = nullptr, *gg = nullptr, *b = nullptr;
        for (ListNode *i = head; i != nullptr; i = i->next) {
            if (i->val < x) {
                if (a == nullptr) {
                    res = i;
                } else {
                    a->next = i;
                }
                a = i;
            } else {
                if (b == nullptr) {
                    gg = i;
                } else {
                    b->next = i;
                }
                b = i;
            }
        }
        if (a)
            a->next = gg;
        if (b)
            b->next = nullptr;
        return res;
    }
};