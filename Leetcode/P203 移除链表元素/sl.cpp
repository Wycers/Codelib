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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* qwq = new ListNode(0);
        qwq->next = head;
        for (ListNode* now = qwq; now != NULL && now->next != NULL; now = now->next)
            while (now->next != NULL && now->next->val == val)
                now->next = now->next->next;
        return qwq->next;
    }
};
