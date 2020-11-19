/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:

    // runtime = O(m*n), space = constant
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        if (m == 0 || n == 0)
            return {};

        vector<vector<int>> compass{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        vector<int> result;
        
        // initial
        // Right, Down, Left, Up. {x, y}
        vector<int> steps{ n, m-1 };

        int direction = 0;
        int row = 0, col = -1;

        // Only consider horizontal and vertical movements
        while (steps[direction % 2])
        {
            for (int i = 0; i < steps[direction % 2]; i++)
            {
                row += compass[direction][0];
                col += compass[direction][1];
                result.push_back(matrix[row][col]);
            }
            steps[direction % 2]--;
            direction = (direction + 1) % 4;
        }
        
        return result;
    }
};
// @lc code=end

