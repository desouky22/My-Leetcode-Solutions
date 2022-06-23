class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = -1 , right = nums.size();
        while(right - left != 1){
            int mid = left + (right - left) / 2;
            if(mid>=0 and mid<nums.size() and nums[mid] >= target)right = mid;
            else left = mid;
        }
        return right;
    }
};