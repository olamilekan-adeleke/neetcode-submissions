class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        for (int n : nums){
            freq[n]++;
        }

        std::vector<std::pair<int, int>> pairs;
        for (auto [num, c]: freq) pairs.push_back({c, num});
        sort(pairs.rbegin(), pairs.rend());

        std::vector<int> res;
        for (auto i = 0; i < k; i++){
            res.push_back(pairs[i].second);
        }
        return res;
    }
};
