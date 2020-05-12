class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int, int> times;
        for(auto i : nums) times[i]++;
        
        for(auto i : times) if(i.second == 1) 
        return i.first;
        return -1;
    }
};
