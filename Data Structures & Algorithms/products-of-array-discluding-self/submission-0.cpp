class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();

        std::vector<int> res(n);

        int prefix = 1;
        for (int i = 0; i < n; i++) {
            res[i] = prefix;
            prefix *= nums[i];
        }

        int surfix = 1;
        for (int i = n -1; i >= 0; i--) {
            res[i] *= surfix;
            surfix *= nums[i];
        }

        return res;
    }
};
