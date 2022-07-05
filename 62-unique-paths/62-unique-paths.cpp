class Solution {
public:
    int n , m;
    int mem[200][200];
    int solve(int row=0, int col=0){
        if(row == n-1 and col == m-1)return 1;
        if(mem[row][col] != -1)return mem[row][col];
        int path1 = 0 , path2 = 0;
        if(row+1 < n) path1 = solve(row+1 , col);
        if(col+1 < m) path2 = solve(row, col+1);
        return mem[row][col] = path1 + path2;
    }
    int uniquePaths(int mm, int nn) {
        n = mm;
        m = nn;
        memset(mem, -1, sizeof mem);
        return solve();
    }
};