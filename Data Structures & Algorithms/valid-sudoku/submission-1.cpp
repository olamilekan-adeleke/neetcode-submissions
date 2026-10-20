class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0}, col[9] = {0}, box[9] = {0};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                const char val = board[r][c];
                if (val == '.') continue;

                const int b = (r / 3) * 3 + c / 3;
                const auto bit = 1 << (val - '0');

                if ((row[r] | col[c] | box[b]) & bit){
                    return false;
                }

                row[r] |= bit;
                col[c] |= bit;
                box[b] |= bit;
            }
        }

        return true;
    }
};
