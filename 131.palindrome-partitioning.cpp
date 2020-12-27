/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
#if __cplusplus < 201703L
#include "leet-code-header.h"
#endif

class Solution {
    bool isPalindrome(const string& s, int l, int r)
    {
        while (l < r)
        {
            if (s[l++] != s[r--])
                return false;
        }

        return true;
    } 

public:
    vector<vector<string>> partition(string s) {
        
    }
};
// @lc code=end

