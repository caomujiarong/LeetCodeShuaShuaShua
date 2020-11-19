/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
#include "leet-code-header.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        if (n <= 1)
            return;

        int temp = 1001;

        // There is N/2 squares or cycles in a matrix
        // Loop from 0 to N/2
        for (int x = 0; x < n/2; x++)
        {
            // Consider elements in group of 4 in current square
            // Loop: Rotate 4 element each time, from corner to the end
            // N - i*2
            // Loop from x to N - x -1
            for (int y = x; y < n - x - 1; y++)
            {
                // The elements in the current group 
                // is (x, y), (y, N-1-x), (N-1-x, N-1-y), (N-1-y, x), 
                // now rotate the these 4 elements
                temp = matrix[x][y];

                matrix[x][y] = matrix[n-y-1][x];
                matrix[n-y-1][x] = matrix[n-x-1][n-y-1];
                matrix[n-x-1][n-y-1] = matrix[y][n-x-1];
                matrix[y][n-x-1] = temp;
            }
        }
    }
};
// @lc code=end

