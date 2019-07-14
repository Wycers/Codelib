/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head != NULL)
        {
            ListNode* l, *r;
            l = r = head;
            for (int i = 0; i < n; ++i)
                r = r->next;
            if (r == NULL)
                return head->next;
            while (r->next != NULL)
            {
                l = l->next;
                r = r->next;
            }
            l->next = l->next->next;
        }
        return head;
    }
};

