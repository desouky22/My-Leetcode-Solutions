class Solution {
public:
    int n;
    vector<int>v;
    vector<vector<int>>all;
    
    int getMaxLen(vector<int>& nums) {
        vector<int>now;
        for(int x = 0; x<nums.size(); x++){
            if(nums[x] == 0) {if(now.size())all.push_back(now);now.clear();}
            else now.push_back(nums[x]);
        }
        if(nums[nums.size()-1] != 0){ all.push_back(now);}
        int ans = 0;
        for(auto it: all){
            int negatives = 0;
            for(auto itt: it) if(itt<0)negatives++;
            if(negatives%2 == 0)ans = max(ans, (int)it.size());
            else{
                int firstNeg = 0 , lastNeg = 0;
                for(int x = 0; x<it.size(); x++){
                    if(it[x] < 0){
                        firstNeg =x;
                        break;
                    }
                }
                
                for(int x = it.size()-1; x>=0; x--){
                    if(it[x] < 0){
                        lastNeg = x;
                        break;
                    }
                }
                int sizeLeft = (int)it.size() - firstNeg - 1;
                int sizeRight = lastNeg;
                cout<<sizeLeft<<" "<<sizeRight<<"\n";
               
                ans = max({ans, sizeLeft, sizeRight});
                
            }
        }
        return ans;
    }
};