class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        for(int x = 1; x<arr.size(); x++){
            if(arr[x-1] < arr[x])continue;
            else return x-1;
        }
        return 0;
    }
};