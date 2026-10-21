class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> s(nums.begin(), nums.end());

        int best = 0;
        for (int num : s) {
            if (s.contains(num - 1)) continue;

            int len = 0;
            while (s.contains(num + len)) len++;
            best = std::max(len, best);
        }
        return best;
    }
};
