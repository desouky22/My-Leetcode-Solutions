class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v;
        int ret = 1 ,mul = 1, zeros = 0;;
        for(auto it : nums) {
            if(it == 0)zeros++;
            if(it!=0)mul*=it;
            ret *= it;
        }
        for(int x = 0; x<nums.size(); x++){
            if(nums[x] == 0){
                if(zeros != 1)v.push_back(0);
                else v.push_back(mul);
            }else v.push_back(ret/nums[x]);
        }
        return v;
        
        
    }
};