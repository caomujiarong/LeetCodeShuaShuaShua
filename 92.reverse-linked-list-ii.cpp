/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */

// @lc code=start
#if __cplusplus < 201703L
#include "leet-code-header.h"
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        ListNode* pre = &dummy;
        ListNode* cur;
        dummy.next = head;

        for (int i = 0; i < m - 1; i++)
        {
            pre = pre->next;
        }

        cur = pre->next;

        // remember this algorithm!!!!!!
        for (int i = 0; i < n - m; i++)
        {
            ListNode* temp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = temp;
        }

        return dummy.next;
    }
};
// @lc code=end

