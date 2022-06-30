class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int target = nums[(int)nums.size() / 2];
        int ret = 0;
        for(auto it : nums)ret += abs(target - it);
        return ret;
    }
};