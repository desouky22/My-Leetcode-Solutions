class Solution {
public:
    int N;
    int mem[100];
    long long solve(int n = 0){
        if(n == N)return 1;
        if(n > N)return 0;
        if(mem[n] != -1)return mem[n];
        
        int path1 = solve(n + 1);
        int path2 = solve(n + 2);
        return mem[n] = path1 + path2;
    }
    int climbStairs(int n) {
        N = n;
        memset(mem, -1, sizeof mem);
        return solve();
    }
};