class Solution {
public:
    long long n , m;
    vector<vector<int>>v;
    int mem[250][250];
    int solve(int row = 0, int col = 0){
        if(row == n-1 and col == m-1)return v[row][col];
        if(mem[row][col] != -1)return mem[row][col];
        int ret = INT_MAX;
        if(row+1 < n) ret = min(ret, v[row][col] + solve(row+1 , col));
        if(col+1 < m) ret = min(ret, v[row][col] + solve(row , col+1));
        return mem[row][col] = ret;
    }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        v = grid;
        memset(mem, -1, sizeof mem);    
        return solve();
    }
};