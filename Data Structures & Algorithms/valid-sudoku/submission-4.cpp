class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            unordered_set<char> seen_row;
            unordered_set<char> seen_col;
            unordered_set<char> seen_box;

            for (int c = 0; c < 9; c++) {
                const char row = board[r][c];
                if (row != '.') {
                    if (seen_row.count(row)) return false;
                    seen_row.insert(row);
                }

                const char col = board[c][r];
                if (col != '.') {
                    if (seen_col.count(col)) return false;
                    seen_col.insert(col);
                }

                const int box_r = (r / 3) * 3 + c / 3;
                const int box_c = (r % 3) * 3 + c % 3;
                const char b = board[box_r][box_c];
                if (b != '.') {
                    if (seen_box.count(b)) return false;
                    seen_box.insert(b);
                }
            }
        }

        return true;
    }
};
