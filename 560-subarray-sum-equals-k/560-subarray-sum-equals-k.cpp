class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 1){
            return nums[0] == k ? 1 : 0;
        }
        vector<long long> prefixSum(nums.size());
        prefixSum[0] = nums[0];
        for(int x = 1; x<nums.size(); x++){
            prefixSum[x] = nums[x] + prefixSum[x-1];
        }
        map<long long, long long>mp;
        mp[0]++;
        int ret = 0;
        for(int x = 0; x<nums.size(); x++){
            ret += mp[prefixSum[x] - k] ;
            mp[prefixSum[x]] ++;
        }
        return ret;
    }
};