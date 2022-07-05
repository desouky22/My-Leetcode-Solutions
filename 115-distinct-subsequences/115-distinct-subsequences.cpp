class Solution {
public:
    int n , m;
    string source , target;
    int mem[1009][1009];
    int solve(int idx1, int idx2){
        if(idx2 == m)return 1;
        if(idx1 == n)return 0;
        if(mem[idx1][idx2] != -1)return mem[idx1][idx2];
        int path1 = 0 , path2 = 0;
        if(source[idx1] == target[idx2]) path1 = solve(idx1+1 , idx2+1);
        path2 = solve(idx1+1, idx2);
        return mem[idx1][idx2] = path1 + path2;
    }
    int numDistinct(string s, string t) {
        n  = s.size();
        m = t.size();
        source = s;
        target = t;
        memset(mem, -1, sizeof mem);
        return solve(0,0);
    }
};