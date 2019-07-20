/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;

        ListNode *tail = head;
        int n;
        for (n = 1; tail->next != NULL; n++)
            tail = tail->next;
        tail->next = head;

        tail = head;
        for (int i = 0; i < n - k % n - 1; i++)
            tail = tail->next;
        head = tail->next;

        tail->next = NULL;

        return head;
    }
};
