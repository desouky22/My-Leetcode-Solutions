class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int x = 0; x<nums.size(); x++){
            ret ^= nums[x];
        }
        return ret;
    }
};