class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = INT_MIN;
        int sum = nums[0];
        for(int x = 1; x<nums.size(); x++){
            ret = max(ret, sum);
            if(sum < 0)sum = nums[x];
            else sum += nums[x];
        }
        ret = max(ret, sum);
        return ret;
    }
};