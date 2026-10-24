
class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word,
               int i, int row, int col) {
        if (i == word.size()) {
            return true;
        }

        if (row < 0 || col < 0 ||
            row >= board.size() || col >= board[0].size() ||
            board[row][col] != word[i]) {
            return false;
        }

        char ch = board[row][col];
        board[row][col] = '#';

        bool found = solve(board, word, i + 1, row + 1, col) ||
                     solve(board, word, i + 1, row - 1, col) ||
                     solve(board, word, i + 1, row, col + 1) ||
                     solve(board, word, i + 1, row, col - 1);

        board[row][col] = ch;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (solve(board, word, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};
