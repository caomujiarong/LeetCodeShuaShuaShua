/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
#if __cplusplus < 201703L
#include "leet-code-header.h"
#endif

class Solution {
    int counts(int n, vector<int>& memo)
    {
        if (n < 0)
        {
            return 0;
        }
        else if (n == 0)
        {
            return 1;
        }
        else if (memo[n] == -1)
        {
            memo[n] = counts(n - 1, memo) + counts(n - 2, memo);
        }

        return memo[n];
    }

public:
    // f(n) = f(n - 1) + f(n - 2)

    int climbStairs(int n) {
        if (n == 0) return 0;
        else if (n == 1) return 1;
        else if (n == 2) return 2;
        
        vector<int> dp(n, -1);
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i < n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n - 1] + dp[n - 2];
    }
};
// @lc code=end

