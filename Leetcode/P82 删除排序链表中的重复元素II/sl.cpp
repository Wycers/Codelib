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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode *tmp = new ListNode(0);
        tmp->next = head;
        ListNode *res = tmp;
        for (ListNode *i = tmp->next; i != NULL; i = i->next) {
            if (i->next != NULL && tmp->next->val == i->next->val)
                continue;
            if (i == tmp->next) {
                tmp = i;
            } else {
                tmp->next = i->next;
            }
        }
        return res->next;
    }
};