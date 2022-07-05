class Solution {
public:
    int n, k ,target;
    int MOD = int(1e9 + 7);
    int mem[40][2000];
    int solve(int index, int sum){
        if(sum == 0 and index == n)return 1;
        if(index == n)return 0;
        if(mem[index][sum] != -1)return mem[index][sum];
        int ret = 0;
        for(int x = 1; x<=k; x++){
            if(sum >= x){
                ret = (ret%MOD + solve(index+1, sum-x)%MOD)%MOD;
                ret %= MOD;
            }
        }
        return mem[index][sum] = ret%MOD;
    }
    int numRollsToTarget(int nn, int kk, int ttarget) {
        n = nn;
        k = kk;
        target = ttarget;
        memset(mem, -1, sizeof mem);
        return solve(0,ttarget);
    }
};