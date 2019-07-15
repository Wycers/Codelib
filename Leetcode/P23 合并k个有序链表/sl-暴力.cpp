/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
        return work(lists, 0, lists.size() - 1);
    }
    ListNode *work(vector<ListNode *> &lists, int l, int r)
    {
        if (r - l == 0)
            return lists[r];
        int mid = (l + r) >> 1;
        ListNode * left = work(lists, l, mid);
        ListNode * right = work(lists, mid + 1, r);
        return mergeTwoLists(left, right);
    }
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
