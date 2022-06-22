class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixSum(n), suffixSum(n);
        prefixSum[0] = nums[0];
        for(int x = 1; x<n; x++){
            prefixSum[x] = prefixSum[x-1] + nums[x];
        }
        suffixSum[n-1] = nums[n-1];
        for(int x = n-2; x>=0; x--){
            suffixSum[x] = suffixSum[x+1] + nums[x];
        }
        
        for(int x = 0; x<n; x++){
            int left = 0 , right = 0;
            if(x) left = prefixSum[x-1];
            if(x != n-1)right = suffixSum[x+1];
            if(left == right)return x;
        }
        return -1;
    }
};