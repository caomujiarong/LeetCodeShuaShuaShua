/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Using Binary search
        // TC: O(nlogn), SC: O(1)
        // pigeon-hole concept
        // Count the number of elements <= middle.
        // If the duplicate is on the left, then count should be more than middle,
        // else it is on the right side.

        // each integer is in the range [1, n] inclusive
        /*int left = 1, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;

            // count the number <= middle
            int count = 0;
            for (const int& element : nums)
            {
                if (element <= mid)
                    ++count;
            }

            if (count > mid)
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;*/


        // Using Floyd Cycle detection
        // TC: O(N), SC: O(1)
        /*
            Assume each nums value as an address just like in linked list node addr.
            Then since there is one number whith duplicates, that means there are multiple instances
            of the same address, so it is a cycle just like in linked list. Do the same thing
            as in linked list.
        */
        int hare = nums[0], tortoise = nums[0];

        // hare move twice fast as tortoise
        do
        {
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        } 
        while (hare != tortoise);
        
        // to find the starting of cycle, make tortoise to start from begining
        tortoise = nums[0];
        while (hare != tortoise)
        {
            hare = nums[hare];
            tortoise = nums[tortoise];
        }
        
        return hare;
    }
};
// @lc code=end

