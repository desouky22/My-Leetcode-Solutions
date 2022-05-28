class Solution {
public:
    int missingNumber(vector<int>& nums) {
        map<int, bool>mp;
        int n = nums.size();
        for(int x = 0; x<n; x++){
            mp[nums[x]] = true;
        }
        for(int x = 0; x<=n; x++){
            if(!mp[x])return x;
        }
        return 0;
    }
};