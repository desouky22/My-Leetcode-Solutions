class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0 , end = 0;
        int sum = 0;
        int ans = INT_MAX;
        while(end < nums.size()){
            sum += nums[end];
            if(sum >= target)ans = min(ans, end - start + 1);
            while(sum > target) {ans = min(ans, end - start + 1);sum-=nums[start++];cout<<start<<" "<<end<<"\n";}
            if(sum == target)ans = min(ans, end - start + 1);
            end ++;
        }
        if(ans == INT_MAX)return 0;
        return ans;
    }
};
