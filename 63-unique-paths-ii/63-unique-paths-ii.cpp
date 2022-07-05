class Solution {
public:
    int n , m;
    vector<vector<int>> v;
    int mem[200][200];
    int solve(int row = 0, int col = 0){
        if(row == 0 and col == 0 and v[row][col] == 1)return 0;
        if(row == n-1 and col == m-1)return 1;
        if(mem[row][col] != -1)return mem[row][col];
        int path1 = 0 , path2 = 0;
        if(row+1 < n and v[row+1][col] == 0) path1 = solve(row+1 , col);
        if(col+1 < m and v[row][col+1] == 0) path2 = solve(row , col+1);
        return mem[row][col] = path1 + path2;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        v = obstacleGrid;
        memset(mem, -1, sizeof mem);
        return solve();
    }
};