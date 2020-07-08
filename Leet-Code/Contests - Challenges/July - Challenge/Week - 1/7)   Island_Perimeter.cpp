class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int p = 0;
        if (grid.size() == 1) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[0][c] == 1) {
                    p += 2;
                }
            }
            return p + 2;
        }
        if (grid[0].size() == 1) {
            for (int r = 0; r < grid.size(); ++r) {
                if (grid[r][0] == 1) {
                    p += 2;
                }
            }
            return p + 2;
        }
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == 1) {
                    if (r > 0 && grid[r - 1][c] == 0) ++p;
                    if (r < grid.size() - 1 && grid[r + 1][c] == 0) ++p;
                    if (c > 0 && grid[r][c - 1] == 0) ++p;
                    if (c < grid[0].size() - 1 && grid[r][c + 1] == 0) ++p;
                    if (c == 0 || c == grid[0].size() - 1) ++p;
                    if (r == 0 || r == grid.size() - 1) ++p;
                }
            }
        }
        return p;
    }
}; 
