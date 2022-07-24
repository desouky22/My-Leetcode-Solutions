class Solution {
public:
    int n, target;
    vector<int>v;
    int mem[1009];
    int solve(int rem){
        if(rem == 0)return 1;
        if(rem < 0)return 0;
        if(mem[rem] != -1)return mem[rem];
        int ret = 0;
        for(int x = 0; x<n; x++){
            ret += solve(rem-v[x]); 
        }
        return mem[rem] = ret;
    }
    int combinationSum4(vector<int>& nums, int t) {
        v = nums;
        n = v.size();
        target = t;
        memset(mem, -1, sizeof mem);
        return solve(target);
    }
};