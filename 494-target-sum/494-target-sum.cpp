class Solution {
public:
    int target, n;
    vector<int>v;
    map<int , map<int , int>>mem;
    map<int , map<int , bool>>solved;
    int solve(int index = 0, int sum = 0){
        if(sum == target and index == n) return 1;
        if(index == n) return 0;
        if(solved[index][sum] == true) return mem[index][sum];
        int path1 = solve(index + 1 , sum+v[index]);
        int path2 = solve(index + 1 , sum-v[index]);
        mem[index][sum] = path1 + path2;
        solved[index][sum] = true;
        return mem[index][sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int ttarget) {
        n = nums.size();
        target = ttarget;
        v = nums;
        return solve();
    }
};