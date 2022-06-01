class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v;
        int idx1 = 0 , idx2 = 0;
        while(idx1<m and idx2<n){
            if(nums1[idx1] < nums2[idx2])
                v.push_back(nums1[idx1++]);
            else 
                v.push_back(nums2[idx2++]);
        }
        while(idx1<m)v.push_back(nums1[idx1++]);                        
        while(idx2<n)v.push_back(nums2[idx2++]);
        nums1 = v;
    }
};