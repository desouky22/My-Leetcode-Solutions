class Solution {
public:
    int n;
    vector<int>v;
    vector<int>prefix , suffix;
    int target;
    
    bool valid(int mid,int neededSufix){
        return suffix[mid]<=neededSufix;
    }
    
    int goLeft(){
        int ret = INT_MAX;
        for(int x = 0; x<n; x++){
            if(prefix[x] > target) break;
            else if(prefix[x] == target) ret = min(ret, x+1);
            else{
                int neededSuffix = target - prefix[x];
                int left = x , right = n;
                while(right - left != 1){
                    int mid = (left + right) / 2;
                    if(valid(mid,neededSuffix))right = mid;
                    else left = mid;
                }
                if(right < n and suffix[right] == neededSuffix)
                    ret = min(ret, (x+1) + ((n-1) - right + 1));
            }
        }
        return ret;
    }
    
    
    int minOperations(vector<int>& nums, int x) {
        n = nums.size();
        v = nums;
        target = x;
        prefix.resize(n) , suffix.resize(n);
        
        prefix[0] = nums[0];
        for(int x = 1; x<n; x++){
            prefix[x] = prefix[x-1] + nums[x];
        }
        
        int ret = INT_MAX;
        suffix[n-1] = nums[n-1];
        if(suffix[n-1] == target)ret = 1;
        
        for(int x = n-2; x>=0; x--){
            suffix[x] = suffix[x+1] + nums[x];
            if(suffix[x] == target)ret = min(ret,(n-1) - x + 1);
        }
        
        int ans = goLeft();
        ret = min(ret, ans);
        return ret == INT_MAX ? -1 : ret;
    }
};