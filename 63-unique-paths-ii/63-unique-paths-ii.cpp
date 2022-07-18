class Solution {
public:
    int n , m;
    int mem[109][109];
    vector<vector<int>> grid;
    bool valid(int row, int col){
        return row>=0 and row<n and col>=0 and col<m and grid[row][col] != 1; 
    }
    int solve(int row = 0, int col = 0){
        if(row == n-1 and col == m-1)return 1;
        if(!valid(row, col))return 0;
        if(mem[row][col] != -1)return mem[row][col];
        int goDown = solve(row+1, col);
        int goRight = solve(row, col+1);
        return mem[row][col] = goDown + goRight;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        grid = obstacleGrid;
        if(grid[n-1][m-1])return 0;
        memset(mem, -1, sizeof mem);
        return solve();
    }
};