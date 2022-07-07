class Solution {
public:
    int n , m;
    string a, b;
    int mem[1000][1000];
    int solve(int idx1 = 0, int idx2 = 0){
        if(idx1 == n or idx2 == m)return abs(n-idx1) + abs(m-idx2);
        if(mem[idx1][idx2] != -1)return mem[idx1][idx2];
        int path1 = INT_MAX , path2 = INT_MAX , path3 = INT_MAX , path4 = INT_MAX;
        if(a[idx1] == b[idx2]) path1 = solve(idx1 + 1 , idx2 + 1);
        if(a[idx1] != b[idx2]) path2 = 1 + solve(idx1 + 1 , idx2 + 1);
        path3 = 1 + solve(idx1 + 1 , idx2);
        path4 = 1 + solve(idx1 , idx2 + 1);
        return mem[idx1][idx2] = min({path1 , path2 , path3 , path4});
    }
    int minDistance(string word1, string word2) {
        a = word1;
        b = word2;
        n = a.size();
        m = b.size();
        memset(mem, -1, sizeof mem);
        return solve();
    }
};