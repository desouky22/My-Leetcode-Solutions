class Solution {
public:
    
    bool valid(int mid , vector<int>&nums, int target){
        return nums[mid] < target;
    }
    
    
    int search(vector<int>& nums, int target) {
        int left = -1 , right = nums.size();
        while(right - left != 1){
            int mid = (left + right) / 2;
            if(valid(mid, nums, target)) left = mid;
            else right = mid;
        }
        if(right < nums.size() and nums[right] == target)return right;
        else return -1;
    }
};