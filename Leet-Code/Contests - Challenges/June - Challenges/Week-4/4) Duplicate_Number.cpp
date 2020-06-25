class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> freq;
        for(auto num : nums) freq[num]++;
        
        map<int,int>::iterator itr;
        for(itr = freq.begin(); itr != freq.end(); itr++){
            if(itr->second > 1) return itr->first;
        }
        
        return -1;
    }
};
