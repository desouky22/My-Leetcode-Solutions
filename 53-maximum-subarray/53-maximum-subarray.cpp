class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>prefixSum(nums.size());
        prefixSum[0] = nums[0];
        for(int x = 1; x<nums.size(); x++) prefixSum[x] = prefixSum[x-1] + nums[x];
        multiset<int>ms;
        int ans = *max_element(nums.begin() , nums.end());
        for(int x = 0; x<nums.size(); x++){
            ans = max(ans, prefixSum[x]);
            ans = max(ans, prefixSum[x] - *ms.begin());
            ms.insert(prefixSum[x]);
        }
        return ans;
    }
};