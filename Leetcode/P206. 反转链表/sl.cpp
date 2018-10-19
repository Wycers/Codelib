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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = NULL;
        while (head)
        {
            ListNode *nx = head->next;
            head->next = pre;
            pre = head = nx;
        }
        return pre;
    }
};