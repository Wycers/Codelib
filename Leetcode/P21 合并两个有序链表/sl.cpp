/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *now, *head;
        now = head = new ListNode(0);
        while (l1 != NULL || l2 != NULL)
        {
            if (l1 == NULL)
            {
                now->next = l2;
                l2 = l2->next;
                now = now->next;
                continue;
            }
            if (l2 == NULL)
            {
                now->next = l1;
                l1 = l1->next;
                now = now->next;
                continue;
            }
            if (l1->val < l2->val)
            {
                now->next = l1;
                l1 = l1->next;
            }
            else
            {
                now->next = l2;
                l2 = l2->next;
            }
            now = now->next;
        }
        return head->next;
    }
};
