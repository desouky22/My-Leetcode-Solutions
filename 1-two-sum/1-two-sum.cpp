class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<int>>mp;
        for(int x = 0; x<nums.size(); x++) mp[nums[x]].push_back(x);
        for(int x = 0; x<nums.size(); x++)
        {
            if(target-nums[x] == nums[x]){
                if(mp[target-nums[x]].size() >= 2){
                    return {mp[target-nums[x]][0] , mp[target-nums[x]][1]};
                }
            }else{
                if(mp[target - nums[x]].size()){
                    return {mp[target - nums[x]][0] , x};                        
                }
            }
        } 
        return {0,0};
    }
};