/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.empty())
            return {};

        vector<int> result;

        for (size_t i = 0; i < nums.size(); i++)
        {
            int pos = abs(nums[i]);
            //  1 ≤ a[i] ≤ n
            if (nums[pos - 1] < 0)
            {
                result.push_back(pos);
            }
            nums[pos - 1] *= -1;
        }
        
        return result;
    }
};
// @lc code=end

