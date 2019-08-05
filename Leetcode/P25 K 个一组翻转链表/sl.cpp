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
    ListNode*  reverseList(ListNode *head, ListNode *tail)
    {
        ListNode *pre = tail;
        if (head == NULL)
            return NULL;
        while (head->next != tail)
        {
            ListNode *nx = head->next;
            head->next = pre;
            pre = head;
            head = nx;
        }
        head->next = pre;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ans = new ListNode(0);
        ans->next = head;

        ListNode *l = ans, *r = ans->next;
        while (true)
        {
            int tmp = k;
            while (tmp--)
            {
                if (r == NULL)
                    return ans->next;
                r = r->next;
            }
            ListNode *t = l->next;
            l->next = reverseList(l->next, r);
            if (t == NULL)
                break;
            if (r == NULL)
                break;
            l = t;
        }
        return ans->next;
    }
};
