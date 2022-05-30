class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long firstMax =  LLONG_MIN, secondMax =  LLONG_MIN, thirdMax= LLONG_MIN;
        for(auto val: nums){
            if(firstMax < val){
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = val;
            }else if(firstMax == val)continue;
            else if(secondMax < val){
                thirdMax = secondMax;
                secondMax = val;
            }else if(secondMax == val)continue;
            else if(thirdMax<val){
                thirdMax = val;
            }
        }
        if(thirdMax == LLONG_MIN)return firstMax;
        else return thirdMax;
        
       
        
    }
};