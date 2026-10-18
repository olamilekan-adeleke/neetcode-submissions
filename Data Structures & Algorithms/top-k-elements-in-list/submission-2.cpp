class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        for (int n : nums){
            freq[n]++;
        }

        std::vector<std::vector<int>> bucket(nums.size() + 1);
        for (auto [num, c]: freq) bucket[c].push_back(num);


        std::vector<int> res;
        for (auto i = bucket.size() - 1; i >= 1; i--){
            for (auto val : bucket[i]){
                res.push_back(val);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};
