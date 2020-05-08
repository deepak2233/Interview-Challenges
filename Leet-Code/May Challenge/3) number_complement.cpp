class Solution {
public:
    int findComplement(int num) {
         int M = ~num;
        int mask = 1;
        while (mask < num) mask = (mask << 1) | 1;
        return M & mask;
    
    }
};
