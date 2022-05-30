class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = *max_element(nums.begin() , nums.end());
        int sum = 0;
        for(int x = 0; x<nums.size(); x++){
            sum += nums[x];
            ret = max(ret, sum);
            if(sum < 0) sum = 0;
        }
        return ret;
    }
};