class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        //dp[i][j] means the biggest square with A[i][j] as bottom-right corner.
            int res=0;
            for (int i=0; i<matrix.size(); i++)
            {
                    for (int j=0; j<matrix[0].size(); j++)
                    {
                         if (matrix[i][j]&&i&&j)  matrix[i][j]+=min({matrix[i-1][j], matrix[i-1][j-1], matrix[i][j-1]});
                         res+=matrix[i][j];
                    }
            }
            return res;
    }
};
