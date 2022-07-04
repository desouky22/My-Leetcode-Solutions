class Solution {
public:
    int mem[50];
    int solve(int n){
        if(n<=1)return n;
        if(mem[n] != -1)return mem[n];
        return mem[n] = solve(n-1) + solve(n-2);
    }
    int fib(int n) {
        memset(mem, -1, sizeof mem);
        return solve(n);
    }
};