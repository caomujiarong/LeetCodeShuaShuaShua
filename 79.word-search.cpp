/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
#if __cplusplus < 201703L
#include "leet-code-header.h"
#endif

class Solution {
private:
    bool checkAdjacent(vector<vector<char>>& board, const string& word, int row, int col, int index)
    {
        // End condition
        if (index == word.size())
            return true;
        
        // Boundary check
        if (row < 0 || col < 0 ||
            row > board.size() - 1 || col > board[0].size() - 1)
            return false;
        
        // Check if match
        if (board[row][col] != word[index])
            return false;
        
        // Mark as visited, avoid duplicating search
        // board and word consists only of lowercase and uppercase English letters.
        board[row][col] = '*';

        // Check up, down, left, right
        bool furtherCheck = checkAdjacent(board, word, row-1, col, index+1) ||  // up
                            checkAdjacent(board, word, row+1, col, index+1) ||  // down
                            checkAdjacent(board, word, row, col-1, index+1) ||  // left
                            checkAdjacent(board, word, row, col+1, index+1);  // right
        // Modify back
        board[row][col] = word[index];

        return furtherCheck;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (checkAdjacent(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};
// @lc code=end

