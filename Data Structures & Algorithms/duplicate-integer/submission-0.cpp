class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> s;

        for (auto n : nums) {
            // std::println("n: {}", n);
            if (s.count(n)) {
                return true;
            }
            s.insert(n);
        }

        return false;
    }
};