class Solution {
public:
    bool isValidAt(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) return false; 
            if (board[i][col] == c) return false; 
        }
        int boxRow = (row / 3) * 3;
        int boxCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[boxRow + i][boxCol + j] == c) return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {  
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValidAt(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board)) return true;
                            board[i][j] = '.'; 
                        }
                    }
                    return false;
                }
            }
        }
        return true; 
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
