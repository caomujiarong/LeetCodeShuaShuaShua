/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
#if __cplusplus < 201703L
#include "leet-code-header.h"
#endif

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;

        const int MAX = amount + 1;
        vector<int> dp(amount + 1, MAX);
        dp[0] = 0;

        sort(coins.begin(), coins.end());

        // 216 ms
        for (int i = 1; i <= amount; i++)
        {
            for (int c : coins)
            {
                if (i - c < 0) 
                    break;

                if (dp[i - c] != MAX) // if it was a previously not reached cell, we do not add use it
                {
                    dp[i] = min(dp[i - c] + 1, dp[i]);
                }
            }
        }

        // 136 ms
        // for (int c : coins)
        // {
        //     for (int i = c; i <= amount; i++)
        //     {
        //         dp[i] = min(dp[i - c] + 1, dp[i]);
        //     }
        // }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }


    // 12 ms
    // int coinChange(vector<int>& coins, int amount) 
    // {
    //     sort(coins.begin(), coins.end());
    //     int min_count = INT_MAX;
    //     coinChange_min(coins, coins.size() - 1, amount, 0, min_count);
    //     return min_count == INT_MAX ? -1 : min_count;
    // } 
    //
    // void coinChange_min(vector<int>& coins, int index, int amount, int count, int& min_count)
    // {
    //     if (amount == 0) min_count = min(min_count, count);
    //     if (index < 0) return;

    //     /* Greedy */
    //     for (int i = amount / coins[index]; i >= 0; --i)
    //     {
    //         if (count + i >= min_count) return; // We use larger coins first. 
    //         coinChange_min(coins, index - 1, amount - coins[index] * i, count + i, min_count);
    //     }
    // }
};
// @lc code=end

