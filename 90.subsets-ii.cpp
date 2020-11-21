/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
#if __cplusplus < 201703L
#include "leet-code-header.h"
#endif

class Solution {
    void recursionSubset(vector<vector<int>>& result, vector<int>& currentSet, const vector<int>& nums, int pos)
    {
        result.push_back(currentSet);

        for (int i = pos; i < nums.size(); i++)
        {
            // check if the former dup has not been put into it && it has same element before
            if (i > pos && nums[i] == nums[i - 1])
                continue;
            
            currentSet.push_back(nums[i]);

            // check next number
            recursionSubset(result, currentSet, nums, i + 1);
            currentSet.pop_back();
        }
    }

public:

    // Recursion
    // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //     vector<vector<int>> res;
    //     vector<int> temp;
    //     sort(nums.begin(), nums.end());
    //     recursionSubset(res, temp, nums, 0);
    //     return res;
    // }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> subs = {{}};
        int startIndex = 0, size = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            startIndex = (i >= 1 && nums[i] == nums[i - 1]) ? size : 0;
            size = subs.size();

            for (int j = startIndex; j < size; j++)
            {
                subs.push_back(subs[j]);
                subs.back().push_back(nums[i]);
            }
        }
        
        return subs;
    }
};
// @lc code=end

