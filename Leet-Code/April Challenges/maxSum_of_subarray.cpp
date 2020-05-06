class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0, max_sum=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(max_sum<sum)
            {
                max_sum=sum;
            }
            if(sum<0)
            {
                sum=0;
            }
        }
        return max_sum;
    }
    
};
