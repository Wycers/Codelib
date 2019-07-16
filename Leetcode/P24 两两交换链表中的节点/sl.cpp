/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode * HEAD = new ListNode(0);
        HEAD->next = head;
        ListNode * now = HEAD;
        while (now != NULL)
        {
            if (now->next == NULL || now->next->next == NULL)
                break;
            ListNode * tmp = now->next->next;
            now->next->next = tmp->next;
            tmp->next = now->next;
            now->next = tmp;

            now = now->next->next;
        }
        return HEAD->next;
    }
};

