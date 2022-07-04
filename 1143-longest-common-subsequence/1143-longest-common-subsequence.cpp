class Solution {
public:
    string a, b;
    int n , m;
    int mem[1000][1000];
    int solve(int x = 0, int y = 0){
        if(x == n or y == m)return 0;
        if(mem[x][y] != -1) return mem[x][y];
        
        if(a[x] == b[y])return mem[x][y] = 1 + solve(x+1,y+1);
        int path1 = solve(x+1,y);
        int path2 = solve(x, y+1);
        return mem[x][y] = max(path1 , path2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        a = text1 , b = text2;
        n = a.size() , m = b.size();
        memset(mem, -1, sizeof mem);
        return solve();
    }
};