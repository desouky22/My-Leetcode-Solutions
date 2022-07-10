class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int start = 0 , end = 0;
        int n = nums.size();
        int ans = INT_MIN , sum = 0;
        while(end < n){
            sum += nums[end];
            ans = max(ans, sum);
            if(sum < 0){
                sum = 0;
                start = end+1;
            }
            end++;
        }
        
        return ans;
    }
};