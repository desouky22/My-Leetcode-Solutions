class NumArray {
public:
    vector<int>prefixSum;
    NumArray(vector<int>& nums) {
        prefixSum.resize(nums.size());
        prefixSum[0] = nums[0];
        for(int x = 1; x<nums.size(); x++){
            prefixSum[x] = prefixSum[x-1] + nums[x];
        }
    }
    
    int sumRange(int left, int right) {
        if(!left)return prefixSum[right];
        else return prefixSum[right] - prefixSum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */