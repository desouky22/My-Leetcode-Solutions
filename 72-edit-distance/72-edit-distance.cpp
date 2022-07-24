class Solution {
public:
    typedef long long ll;
    string a, b;
    int n ,m;
    ll mem[509][509];
    ll solve(int idx1 = 0, int idx2 = 0){
        if(idx2 == m) return n - idx1;
        if(idx1 == n) return m - idx2;
        if(mem[idx1][idx2] != -1) return mem[idx1][idx2];
        if(a[idx1] == b[idx2])return mem[idx1][idx2] = solve(idx1 + 1 , idx2 + 1);
        ll path1 = 1 + solve(idx1 + 1 , idx2);
        ll path2 = 1 + solve(idx1, idx2 + 1);
        ll path3 = 1 + solve(idx1+1, idx2+1);
        return mem[idx1][idx2] = min({path1 , path2, path3});
    }
    int minDistance(string word1, string word2) {
        a = word1, b = word2;
        n = a.size() , m = b.size();
        memset(mem, -1, sizeof mem);
        return solve();
    }
};


