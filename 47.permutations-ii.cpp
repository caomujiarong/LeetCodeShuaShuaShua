/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
#if __cplusplus < 201703L
#include "leet-code-header.h"
#endif

class Solution {
    /*
    From right to left. Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
    From right to left. Find the largest index l > k such that nums[k] < nums[l].
    Swap nums[k] and nums[l].
    Reverse the sub-array nums[k + 1:]
    */
    bool next_permutation(vector<int>& nums)
    {
        int n = nums.size();
        int k, l;

        for (k = n - 2; k >= 0; k--)
        {
            if (nums[k] < nums[k + 1])
            {
                break;
            }
        }

        // if not find
        if (k < 0)
        {
            reverse(nums.begin(), nums.end());
            return false;
        }
        else
        {
            for (l = n - 1; l > k; l--)
            {
                if (nums[k] < nums[l])
                {
                    break;
                }
            }

            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
            return true;
        }
    }

    void generate_permute_aux(vector<int> nums, vector<vector<int>>& result, int begin)
    {
        // termination
        if (begin == nums.size())
        {
            result.push_back(nums);
            return;
        }

        for (int i = begin; i < nums.size(); i++)
        {
            // Check for duplicate numbers
            if (i == begin || nums[i] != nums[begin])
            {
                swap(nums[begin], nums[i]);
                generate_permute_aux(nums, result, begin + 1);
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        // do
        // {
        //     result.push_back(nums);
        // } 
        // while (next_permutation(nums));

        generate_permute_aux(nums, result, 0);

        return result;
    }
};
// @lc code=end

