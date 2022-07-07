class Solution {
public:
    vector<int>v;
    int n;
    int mem[10009];
    long long solve(int index){
        if(index >= n-1)return 0;
        if(mem[index] != -1)return mem[index];
        if(v[index] == 0) return INT_MAX;
        long long ret = INT_MAX;
        for(int x = 1; x<=v[index]; x++){
            ret = min(ret, solve(index+x) + 1);
        }
        return mem[index] = ret;
    }
    int jump(vector<int>& nums) {
        n = nums.size();
        v = nums;
        memset(mem, -1, sizeof mem);
        return solve(0);
    }
};