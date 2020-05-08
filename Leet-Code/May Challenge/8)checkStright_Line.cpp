class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()<=2)
            return true;
        for(int i=3;i<coordinates.size();i++)
        {
            if((coordinates[i][0] - coordinates[i - 1][0]) * (coordinates[i - 1][1] - coordinates[i - 2][1]) !=
                (coordinates[i - 1][0] - coordinates[i - 2][0]) * (coordinates[i][1] - coordinates[i - 1][1]))
                return false;
        }
        return true;
    }
};
