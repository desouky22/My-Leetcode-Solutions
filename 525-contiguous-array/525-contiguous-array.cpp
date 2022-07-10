class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int>v;
        int n = nums.size();
        for(auto it: nums){
            if(it == 0)v.push_back(-1);
            else v.push_back(1);
        }
        
        int sum = 0 , ans = 0;
        map<int , int>mp;
        mp[0] = 0;
        for(int x = 0; x<n; x++){
            sum += v[x];
            if(sum == 0) ans = max(ans, x+1);
            if(mp.count(sum) != 0)
                ans = max(ans, x - mp[sum]);
            else mp[sum] = x;
        }
        return ans;
    }
};
