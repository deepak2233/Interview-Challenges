class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int sum = 0;
        for(auto i:J)
        {
            for(auto j:S)
            {
                if(i==j) sum++;
            }
        }
        return sum;
    }
};
