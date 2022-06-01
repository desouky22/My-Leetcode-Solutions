class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>prefixMin(nums.size()) , suffixMax(nums.size());
        prefixMin[0] = nums[0];
        for(int x = 1; x<nums.size(); x++){
            prefixMin[x] = min(prefixMin[x-1] , nums[x]);
        }
        
        suffixMax[nums.size()-1] = nums[nums.size()-1];
        for(int x = nums.size()-2; x>=0; x--){
            suffixMax[x] = max(nums[x] , suffixMax[x+1]);
        }
        
        for(int x =1; x<nums.size()-1; x++){
            if(prefixMin[x-1] <nums[x] and suffixMax[x+1] > nums[x])return true;
        }
        return false;
        
        
    }
};