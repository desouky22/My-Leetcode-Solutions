class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int ,bool> mp;
        int sum = 0;
        int right = 0,ret = 0,left = 0;
        while(right < nums.size()){
            if(!mp[nums[right]]){
                mp[nums[right]] = 1;
                sum += nums[right];
                right ++;
                ret = max(ret, sum);
            }else{
                while(left <= right and mp[nums[right]] == true){
                    sum -= nums[left];
                    mp[nums[left]] = false;
                    left ++;
                }
            }
        }
        ret = max(ret, sum);
        return ret;
    }
};