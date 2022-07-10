class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0 , end = 0;
        int n = nums.size();
        int ans = 0;
        int remaining = k;
        while(end<n){
            ans = max(ans, end-start);
            if(nums[end] == 1) end ++;
            else {
                if(remaining > 0) {
                    end ++;
                    remaining --;
                }else{
                    if(nums[start] == 0)remaining++;
                    start ++;
                }
            }
        } 
        ans = max(ans, end-start);

        return ans;
    }
};