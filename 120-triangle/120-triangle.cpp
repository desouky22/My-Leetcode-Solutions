class Solution {
public:
    vector<vector<int>> triangle;
    int n;
    int mem[201][201];
    int solve(int row, int col){
        if(row == n) return 0;
        if(mem[row][col] != -1) return mem[row][col];
        int path1 = INT_MAX , path2 = INT_MAX;
        path1 = triangle[row][col] + solve(row+1, col);
        path2 = triangle[row][col] + solve(row+1, col+1);
        return mem[row][col] = min(path1 , path2);
    }
    
    int minimumTotal(vector<vector<int>>& t) {
        triangle = t;
        n = t.size(); 
        memset(mem, -1, sizeof mem);
        return solve(0,0);
    }
};