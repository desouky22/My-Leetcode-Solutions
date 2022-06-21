class Solution {
public:
    int n;
    vector<int>v;
    int l , b;
    bool valid(int index){
        if(index>=n)return false;
        vector<int>diff;
        for(int x = 0; x<index; x++){
            if(v[x] >= v[x+1]) continue;
            diff.push_back(v[x+1] - v[x]);
        }
        sort(diff.begin() , diff.end());
        int tempL = l;
        while(tempL and diff.size()){
            diff.pop_back();
            tempL--;
        }
        
        int sum = 0;
        for(auto it: diff){
            sum += it;
        }
        return sum <= b;
    }
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        v = heights;
        n = v.size();
        l = ladders;
        b = bricks;
        int left = -1 , right = n+1;
        while(right - left != 1){
            int mid = left + (right - left) / 2;
            if(valid(mid)) left = mid;
            else right = mid;
        }
        return left;
    }
};