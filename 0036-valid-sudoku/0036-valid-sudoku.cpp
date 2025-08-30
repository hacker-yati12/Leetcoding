class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> vec(9, 0);
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(!isdigit(board[i][j]))
                    continue;
                if(isdigit(board[i][j]) && vec[(board[i][j]-'0') - 1])
                    return false;
                vec[(board[i][j]-'0') - 1] = 1;
            }
            vec.assign(9, 0);
        }
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(!isdigit(board[j][i]))
                    continue;
                if(isdigit(board[j][i]) && vec[(board[j][i] - '0') - 1])
                    return false;
                vec[(board[j][i] - '0') - 1] = 1;
            }
            vec.assign(9, 0);
        }
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                for(int k=i*3; k<i*3+3; k++) {
                    for(int l=j*3; l<j*3+3;l++) {
                        if(!isdigit(board[k][l]))
                            continue;
                        if(isdigit(board[k][l]) && vec[(board[k][l] - '0') - 1])
                            return false;
                        vec[(board[k][l] - '0') - 1] = 1;
                    }
                }
                vec.assign(9, 0);
            }
        }
        return true;
    }
};