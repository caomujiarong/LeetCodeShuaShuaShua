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


    // Recursion without memorize
    int isTarget(vector<int>& nums, int S, int curr_sum, int index)
    {        
        if (index < 0)
        {
            if (curr_sum == S)
                return 1;
            else
                return 0;
        }
        
        int take = isTarget(nums, S, curr_sum + nums[index], index - 1);
        int notTake = isTarget(nums, S, curr_sum - nums[index], index - 1);

        return take + notTake;
    }

public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int current_sum = 0;

        return isTarget(nums, S, current_sum, nums.size() - 1);
    }


};
// @lc code=end

