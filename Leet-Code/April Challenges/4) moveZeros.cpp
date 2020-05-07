class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int r=0,l=0;
         if(nums.size()==0 || nums.size()==1)
    {
        return;
    }

     while(r!=nums.size()){
        if(nums[r]==0)
            ++r;
        else{
            swap(nums[l],nums[r]);
            ++l;
            ++r;
        }
     }
    }
};
