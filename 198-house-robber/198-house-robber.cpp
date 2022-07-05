class Solution {
public:
    int n;
    vector<int>v;
    int mem[200];
    int solve(int index = 0){
        if(index >= n)return 0;
        if(mem[index] != -1)return mem[index];
        int path1 = v[index] + solve(index+2);
        int path2 = solve(index+1);
        return mem[index] = max(path1 , path2);
    }
    int rob(vector<int>& nums) {
        v = nums;
        n = nums.size();
        memset(mem, -1, sizeof mem);
        return solve();
    }
};