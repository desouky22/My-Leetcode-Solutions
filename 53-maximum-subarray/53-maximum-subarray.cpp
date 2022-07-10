class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sum = nums[0];
        for(int x = 1; x<nums.size(); x++){
            ans = max(ans, sum);
            if(sum >= 0) sum += nums[x];
            else sum = nums[x];
            ans = max(ans, sum);
        }
        ans = max(ans, sum);
        
        return ans;
        
    }
};