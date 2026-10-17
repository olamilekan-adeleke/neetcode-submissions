class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        for (auto n : nums) freq[n]++;

        vector<vector<int>> bucket(nums.size() + 1);
        for (auto [num, c] : freq) bucket[c].push_back(num);

        vector<int> res;
        for (int i = nums.size(); i >= 1; i--){
            for (int num : bucket[i]){
                res.push_back(num);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};
