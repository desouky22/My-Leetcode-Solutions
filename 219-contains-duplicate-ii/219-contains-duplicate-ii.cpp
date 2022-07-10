class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int , bool>exist;
        k = min(k, int(nums.size()-1));
        for(int x = 0; x<=k; x++) {
            if(exist[nums[x]])return true;
            exist[nums[x]] = true;
        }
        
        for(int x = k+1; x<nums.size(); x++){
            exist[nums[x-(k+1)]] = false;
            if(exist[nums[x]])return true;
            exist[nums[x]] = true;
        }
        return false;
    }
};