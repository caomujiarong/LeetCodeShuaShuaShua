/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
    // Pass by reference. Modify input matrix.
    void setZeroes(vector<vector<int>>& matrix) {
        // initialize
        int rows = matrix.size(), cols = matrix[0].size();
        bool col0 = false;

        // For row: check if there any zero? use the 1st element of the row to store the states
        // For col: check if there any zero? use the 1st element of the col to store the states
        for (size_t i = 0; i < rows; i++)
        {
            if (matrix[i][0] == 0)
                col0 = true;

            for (size_t j = 1; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        // Go through each element in a bottom-up way.
        // if there is any matrix[?][0] or matrix[0][?] is zero, change to zero
        for (size_t i = rows - 1; i >= 0; i--)
        {
            for (size_t j = cols - 1; j >= 1; j--)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            
            if (col0 == true)
                matrix[i][0] = 0;
        }
    }
};
// @lc code=end

