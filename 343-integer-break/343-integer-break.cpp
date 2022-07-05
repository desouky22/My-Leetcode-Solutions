class Solution {
public:
    int n;
    int mem[100][100];
    int solve(int sum, int numberOfElements){
        if(sum == 0 and numberOfElements >= 2) return 1;
        if(sum == 0)return 0;
        if(mem[sum][numberOfElements] != -1)return mem[sum][numberOfElements];
        int path1 = 1;
        for(int x = 1; x<=sum; x++){
            path1 = max(path1 , x * solve(sum-x, numberOfElements+1)); 
        }
        return mem[sum][numberOfElements] = path1;
    }
    int integerBreak(int nn) {
        n = nn;
        memset(mem, -1, sizeof mem);
        return solve(nn, 0);
    }
};