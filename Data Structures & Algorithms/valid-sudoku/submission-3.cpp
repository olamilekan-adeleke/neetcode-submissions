class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            std::unordered_set<char> seenRow = {};
            for (int c = 0; c < 9; c++) {
                const char val = board[r][c];
                if (val == '.') continue;

                if (seenRow.count(val)) return false;
                seenRow.insert(val);
            }
        }

        for (int r = 0; r < 9; r++) {
            std::unordered_set<char> seenCol = {};
            for (int c = 0; c < 9; c++) {
                const char val = board[c][r];
                if (val == '.') continue;

                if (seenCol.count(val)) return false;
                seenCol.insert(val);
            }
        }

        for (int r = 0; r < 9; r++) {
            std::unordered_set<char> seenBox = {};
            for (int c = 0; c < 9; c++) {
                const auto boxR = (r / 3) * 3 + c / 3;
                const auto boxC = (r % 3) * 3 + c % 3;

                const char val = board[boxR][boxC];
                if (val == '.') continue;

                if (seenBox.count(val)) return false;
                seenBox.insert(val);
            }
        }

        return true;
    }
};
