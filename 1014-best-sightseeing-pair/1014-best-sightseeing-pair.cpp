class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int>v(values);
        vector<int>preMax(n) , postMax(n);
        for(int x = 0; x<n-1; x++) preMax[x] = v[x] + x;
        for(int x = 1; x<n; x++) postMax[x] = v[x] - x;
        for(int x = n-2; x>=0; x--) postMax[x] = max(postMax[x+1] , postMax[x]);
        int ret = INT_MIN;
        for(int x = 0; x < n-1; x++){
            ret = max(ret, preMax[x]+postMax[x+1]);
        }
        return ret;
    }
};

/// 8 1 5 2 6
/// 0 1 2 3 4
/// 8 2 7 5 
///   0 3 -1 2