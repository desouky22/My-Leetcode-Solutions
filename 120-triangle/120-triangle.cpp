class Solution {
public:
    vector<vector<int>>v;
    int dp[205][200];
    int solve(int row, int col){
        if(row == v.size()) return 0;
        if(dp[row][col] != -1)return dp[row][col];
        int path1 = solve(row+1, col+1) + v[row][col];
        int path2 = solve(row+1, col) + v[row][col];
        return dp[row][col] = min(path1 , path2);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        v = triangle;
        memset(dp , -1, sizeof dp);
        return solve(0,0);
    }
};