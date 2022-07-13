class Solution {
public:
    typedef long long ll;
    vector<string>v;
    string target;
    map<string , ll> mem;
    map<string, bool> validPrefix;
    ll solve(string s = ""){
        if(!validPrefix[s])return -1;
        if(s.size() > target.size()) return -1;
        if(s == target) return 1;
        if(mem[s] != 0) return mem[s];
        ll ret = -1;
        for(auto it :v){
            ret = max(ret, solve(s + it));
        }
        return mem[s] = ret;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        target = s;
        v = wordDict;
        string prefix;
        validPrefix[prefix] = true;
        for(int x = 0; x<s.size(); x++){
            prefix += s[x];
            validPrefix[prefix] = true;
        }
        return solve() != -1;
    }
};