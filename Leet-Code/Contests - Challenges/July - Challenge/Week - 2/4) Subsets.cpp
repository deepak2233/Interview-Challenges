class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> dp;
        
        dp.push_back({});
        
        for (auto i = 0; i < nums.size(); i++) {
            auto size = dp.size();

            for (auto j = 0; j < size; j++) {
                auto v = dp[j];
                v.push_back(nums[i]);
                dp.push_back(v);
            }
        }
        return dp;
    }
};
