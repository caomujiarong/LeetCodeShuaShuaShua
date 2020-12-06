/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#if __cplusplus < 201703L
#include "leet-code-header.h"
#endif

class Solution {
    void generate_permute_aux(vector<int> & nums, vector<vector<int>>& result, int begin)
    {
        // termination check
        if (begin == nums.size())
        {
            result.push_back(nums);
            return;
        }
        
        // generate nodes
        /*
        It runs a loop from our current index to size of array. 
        In each iteration of that loop it swaps the current index and loop variable. 
        Right at that point it calls the permutation function again recursively to 
        generate all further permutations of this swapped state. 
        Once that call is done, it swaps back the variables to original state. 
        This is required because for e.g. after we are done with generating for x (yz and zy) 
        we want to start from the original state again i.e. original state was xyz 
        so now we move y to the first place by swapping it with x, so y followed by xz 
        and then zx would be the sequence. 
        */

       // The running time of this algorithm is n! 
        for (int i = begin; i < nums.size(); i++)
        {
            swap(nums[begin], nums[i]);
            generate_permute_aux(nums, result, begin + 1);
            swap(nums[begin], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        generate_permute_aux(nums, result, 0);
        return result;
    }
};
// @lc code=end

