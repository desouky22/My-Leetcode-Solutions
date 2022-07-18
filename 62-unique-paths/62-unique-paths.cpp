class Solution {
public:
    int n, m;
    int mem[109][109];
    bool valid(int row, int col){
        return row>=0 and row<n and col>=0 and col<m;
    }
    int solve(int row = 0, int col = 0){
        if(row == n-1 and col == m-1)return 1;
        if(!valid(row, col))return 0;
        if(mem[row][col] != -1)return mem[row][col];
        int goRight = solve(row, col+1);
        int goDown = solve(row+1, col);
        return mem[row][col] = goRight + goDown;
    }
    int uniquePaths(int N, int M) {
        n = N;
        m = M;
        memset(mem, -1, sizeof mem);
        return solve();
    }
};