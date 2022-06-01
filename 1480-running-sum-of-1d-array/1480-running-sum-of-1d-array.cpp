class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ret;
        ret.push_back(nums[0]);
        for(int x = 1; x<nums.size(); x++){
            ret.push_back(ret.back() + nums[x]);
        }
        return ret;
    }
};