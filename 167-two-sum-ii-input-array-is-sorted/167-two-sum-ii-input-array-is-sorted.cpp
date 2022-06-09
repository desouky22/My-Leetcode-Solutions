class Solution {
public:
    bool valid(int val, int target){
        return val >= target;
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(); //4
        for(int x = 0; x<n-1; x++){
            int left = x , right = n;// 0 4
            int newTarget = target - numbers[x]; // 7
            while(right - left != 1){
                int mid = (left + right) / 2;
                if(valid(numbers[mid],newTarget))right = mid;
                else left = mid;
            }
            if(right<n and numbers[right] == newTarget)return {x+1, right+1};
        }
        return {0,0};  
    }
};