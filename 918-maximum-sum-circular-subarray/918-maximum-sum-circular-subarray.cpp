class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mx = *max_element(nums.begin() , nums.end());
        if(mx <= 0)return mx;
        int n = nums.size();
        vector<int> v = nums;
        for(int x = 0; x<nums.size(); x++) v.push_back(nums[x]);
        
        vector<int>prefixSum(v.size());
        prefixSum[0] = v[0];
        for(int x = 1; x<v.size(); x++)prefixSum[x] = v[x] + prefixSum[x-1];
        int ret = INT_MIN;
        multiset<int>ms;
        for(int x = 0; x<v.size(); x++){
            if(x > n) ms.erase(ms.find(prefixSum[x-n-1]));
            ms.insert(prefixSum[x]);
            ret = max(ret, prefixSum[x] - *ms.begin());
        }
        return ret;
    }    
 
};