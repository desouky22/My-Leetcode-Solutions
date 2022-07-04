class Solution {
public:
    int mem[50];
    int solve(int n){
        if(n == 0)return 0;
        if(n == 1 or n == 2)return 1;
        if(mem[n]!= -1)return mem[n];
        return mem[n] = solve(n-1) + solve(n-2) + solve(n-3);
    }
    int tribonacci(int n) {
        memset(mem, -1, sizeof mem);
        return solve(n);
    }
};