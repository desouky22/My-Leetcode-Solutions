class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin() , boxTypes.end() , cmp);
        int ret = 0 , boxes = 0;;
        for(int x = 0; x<boxTypes.size(); x++){
            if(boxTypes[x][0] + boxes <= truckSize)
                {ret += boxTypes[x][0] * boxTypes[x][1];boxes += boxTypes[x][0];}
            else if(truckSize - boxes >= 0){
                {ret += (truckSize - boxes) * boxTypes[x][1];boxes += truckSize - boxes;}
            }else break;
                
        }
        return ret;
    }
};