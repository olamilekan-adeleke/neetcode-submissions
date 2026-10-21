class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> res(nums.begin(), nums.end());

        int prefix = 1;
        for (int i = 0; i < nums.size(); i++) {
            res[i] = prefix;
            prefix *= nums[i];
        }

        int surfix = 1;
        for (int i = nums.size() - 1; i >=0; i--){
            res[i] *= surfix;
            surfix *= nums[i];
        }

        return res;
    }
};
