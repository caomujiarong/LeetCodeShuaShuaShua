/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
#if __cplusplus < 201703L
#include "leet-code-header.h"
#endif

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        
        if (m == 0 || n == 0)
            return 0;

        vector<vector<int>> longestEdgeMap(m, vector<int>(n, 0));
        int result = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0 || matrix[i][j] == '0')
                {
                    longestEdgeMap[i][j] = matrix[i][j] - '0';
                }
                else
                {
                    longestEdgeMap[i][j] = 1 + min(
                        longestEdgeMap[i - 1][j],
                        min(longestEdgeMap[i][j - 1], longestEdgeMap[i - 1][j - 1]));
                }

                result = max(result, longestEdgeMap[i][j]);
            }
        }
        
        return result * result;
    }
};
// @lc code=end

