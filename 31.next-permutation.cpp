/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
#if __cplusplus < 201703L
#include "leet-code-header.h"
#endif

class Solution {
public:
    /*
    From right to left. Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
    From right to left. Find the largest index l > k such that nums[k] < nums[l].
    Swap nums[k] and nums[l].
    Reverse the sub-array nums[k + 1:]

    here is an example:
    2,3,6,5,4,1
    Step1, from right to left, find the first number which not increase in a ascending order. In this case which is 3.
    Step2, here we can have two situations:

    We cannot find the number, all the numbers increasing in a ascending order. This means this permutation is the last permutation, we need to rotate back to the first permutation. So we reverse the whole array, for example, 6,5,4,3,2,1 we turn it to 1,2,3,4,5,6.

    We can find the number, then the next step, we will start from right most to leftward, try to find the first number which is larger than 3, in this case it is 4.
    Then we swap 3 and 4, the list turn to 2,4,6,5,3,1.
    Last, we reverse numbers on the right of 4, we finally get 2,4,1,3,5,6.

    Time complexity is: O(3*n)=O(n).
    */
    void nextPermutation(vector<int>& nums) {
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
        }
    }
};
// @lc code=end

