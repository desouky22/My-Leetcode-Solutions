class Solution {
public:
    vector<int>freq;
    int mem[10009];
    int solve(int val){
        if(val <= 0)return 0;
        if(mem[val]!= -1)return mem[val];
        int path1 = freq[val]*val + solve(val - 2);
        int path2 = solve(val - 1);
        return mem[val] = max(path1 , path2);
    }
    int deleteAndEarn(vector<int>& nums) {
        freq.resize(1e4 + 1);
        for(int x = 0; x<nums.size(); x++) freq[nums[x]] ++;
        memset(mem, -1, sizeof mem);
        return solve(*max_element(nums.begin() , nums.end()));
    }
};