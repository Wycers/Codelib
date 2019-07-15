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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *now, *head;
        now = head = new ListNode(0);
        while (true)
        {
            int min = 0x7fffffff;
            ListNode ** tmp = NULL;
            for (int i = 0, len = lists.size(); i < len; ++i)
                if (lists[i] != NULL && lists[i]->val < min)
                    {
                        min = lists[i]->val;
                        tmp = &lists[i];
                    }
            if (tmp == NULL)
                break;
            now->next = *tmp;
            now = now->next;
            *tmp = (*tmp)->next;
        }
        return head->next;
    }
};

