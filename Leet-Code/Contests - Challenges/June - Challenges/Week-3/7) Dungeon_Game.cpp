class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.size()==0) return 1;
        int rs = dungeon.size(), cs = dungeon[0].size();
        vector<int> dp(cs+1, INT_MAX);
        dp[cs] = 1;
        for(int i=rs-1; i>=0; --i){
            for(int j=cs-1; j>=0; --j){
                dp[j] = max(1, min(dp[j], dp[j+1]) - dungeon[i][j]);
            }
            dp[cs] = INT_MAX;
        }
        return dp[0];
    }
};
