/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode* last = head;
        for (ListNode* i = head; i != NULL; i = i->next)
        {
            if (i->next != NULL && last->val == i->next->val)
                continue;
            last->next = i->next;
            last = i->next;
        }
        return head;
    }
};
