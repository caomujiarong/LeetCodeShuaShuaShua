/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
#if __cplusplus < 201703L
#include "leet-code-header.h"
#endif

class Solution {


//     // Recursion without memorize
//     int isTarget(vector<int>& nums, int S, int curr_sum, int index)
//     {        
//         if (index < 0)
//         {
//             if (curr_sum == S)
//                 return 1;
//             else
//                 return 0;
//         }
        
//         int take = isTarget(nums, S, curr_sum + nums[index], index - 1);
//         int notTake = isTarget(nums, S, curr_sum - nums[index], index - 1);

//         return take + notTake;
//     }

// public:
//     int findTargetSumWays(vector<int>& nums, int S) {
//         int current_sum = 0;

//         return isTarget(nums, S, current_sum, nums.size() - 1);
//     }

public:
    int findTargetSumWays(vector<int>& nums, int S) {
        
        if (nums.size() == 0)
            return 0;

        /*                  
            sum(P) - sum(N) = target
            sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
            2 * sum(P) = target + sum(nums) 
        */
        int all = accumulate(nums.begin(), nums.end(), 0);

        if (S < -all || S > all)
            return 0;

        if ((all + S) % 2 != 0)
            return 0;

        int sum_positive = (all + S) / 2;

        // dp is 2-d array with dp[i][j] means number of ways to get sum j with first i elements from nums.
        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum_positive + 1, 0));

        // ** When sum = 0:
        // ** dp[0][0] means we have nothing, and our goal is 0, just can pick noting => 1 choice,
        // ** dp[1][0] means we have { nums[0] }, and our goal is 0, just can pick noting => 1 choice,
        // ** dp[2][0] means we have { nums[0], nums[1] }, and our goal is 0, just can pick noting => 1 choice,
        // ** and so on...
        for (int i = 0; i <= nums.size(); i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= nums.size(); i++)
        {
            for (int current_sum = 0; current_sum <= sum_positive; current_sum++)
            {
                // we have { nums[0], ..., nums[i - 1] }, our goal is current sum;
                // first, we can always not take nums[i - 1]
                dp[i][current_sum] = dp[i - 1][current_sum];
                if (current_sum >= nums[i - 1])
                {
                    // Consider current sum - nums[i - 1], which means, we've already
                    // take element nums[i - 1].
                    // Accumulate the ways of the "goal minus nums[i - 1]" using { nums[0], ..., nums[i - 1] }
                    dp[i][current_sum] += dp[i - 1][current_sum - nums[i - 1]];
                }
            }
        }

        return dp[nums.size()][sum_positive];
    }


};
// @lc code=end

