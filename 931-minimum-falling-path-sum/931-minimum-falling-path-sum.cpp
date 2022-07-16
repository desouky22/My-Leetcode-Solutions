class Solution {
public:
    vector<vector<int>> grid;
    int n ,m;
    int mem[101][101];
    int solve(int row, int col){
        if(row == n)return 0;
        if(mem[row][col] != -1)return mem[row][col];
        int path1 = INT_MAX , path2 = INT_MAX , path3 = INT_MAX;
        path1 = grid[row][col] + solve(row+1, col); 
        if(col+1<m) path2 = grid[row][col] + solve(row+1, col+1);
        if(col-1>=0) path3 = grid[row][col] + solve(row+1, col-1);
        return mem[row][col] = min({path1 , path2 , path3});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        grid = matrix;
        n = grid.size();
        m = grid[0].size();
        int ans = INT_MAX;
        for(int x = 0; x<m; x++){
            memset(mem, -1, sizeof mem);
            ans = min(ans, solve(0, x));
        }
        return ans;
    }
};