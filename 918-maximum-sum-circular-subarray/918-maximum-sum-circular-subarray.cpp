class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int>v = nums;
        for(auto it: nums) v.push_back(it);
        vector<int>prefixSum(v.size());
        prefixSum[0] = v[0];
        for(int x = 1; x<v.size(); x++) prefixSum[x] = prefixSum[x-1] + v[x];
        int ans = *max_element(v.begin() , v.end());
        multiset<int>ms;
        for(int x = 0; x<v.size(); x++){
            if(x < n) ans = max(ans, prefixSum[x]);
            ans = max(ans, prefixSum[x] - *ms.begin());
            ms.insert(prefixSum[x]);
            if(ms.size() == n) ms.erase(ms.find(prefixSum[x - n + 1]));
        }
        return ans;
    }
};