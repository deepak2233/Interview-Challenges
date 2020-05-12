  
class Solution {
public:
    bool isPerfectSquare(int num) {
        int sq = (sqrt(num));
        
        if(num==sq*sq)
        {
            return true;
        }
        else
            return false;
    }
};
