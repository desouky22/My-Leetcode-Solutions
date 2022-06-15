class Solution {
public:
    int n;
    int dp[1001][1001];
    vector<string>v;
    
    bool isValid(string &greater, string &smaller){
        if(smaller.empty())return true;
        if(greater.size() - smaller.size() != 1) return false;
        
        int idx = 0;
        while(idx < smaller.size() and greater[idx] == smaller[idx]){
            idx ++;
        }
        
        idx ++;
        
        while(idx<greater.size()){
            if(smaller[idx-1] != greater[idx])return false;
            idx++;
        }
        return true;
    } 
    
    int solve(int index, int prev){ 
        if(index == n) return 0;
        int &ret = dp[index][prev];
        if(~ret)return ret;
        int path1 = 0 , path2 = 0 ;
        if(isValid(v[index] , v[prev]))
            path1 = solve(index + 1 , index) + 1;
        path2 = solve(index + 1 , prev);
        
        return ret = max(path1 , path2);
    }
   
    int longestStrChain(vector<string>& words) {
        memset(dp, -1, sizeof dp);
        words.push_back("");
        sort(words.begin() , words.end() , [](string &a, string &b){return a.size() < b.size();});
        n = words.size(); v = words;
        return solve(0,0) -1;
    }
};