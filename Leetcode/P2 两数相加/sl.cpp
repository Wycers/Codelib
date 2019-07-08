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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL)
            return NULL;

        ListNode* res = new ListNode(0);
        ListNode* now = res;
        bool flag = true;
        while (l1 != NULL || l2 != NULL)
        {
            if (!flag)
            {
                now->next = new ListNode(0);
                now = now->next;
            }
            now->val += getVal(&l1) + getVal(&l2);
            if (flag = (now->val > 9))
            {
                now->next = new ListNode(1);
                now->val -= 10;
                now = now->next;
            }
        }
        return res;
    }
    inline int getVal(ListNode** node)
    {
        if (*node == NULL)
            return 0;
        int tmp = (*node)->val;
        *node = (*node)->next;
        return tmp;
    }
};
