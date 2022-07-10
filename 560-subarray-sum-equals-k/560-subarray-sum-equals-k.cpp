class Solution {
public:
    int n , target;
    vector<int>v;
    int subarraySum(vector<int>& nums, int k) {
        v = nums;
        n = v.size();
        target = k;
        map<int , int>mp;
        mp[0] ++;
        int sum = 0 , ans = 0;
        for(int x = 0; x<n; x++){
            sum += v[x];
            ans += mp[sum-k];
            mp[sum] ++;
        }
        return ans;
    }
};
