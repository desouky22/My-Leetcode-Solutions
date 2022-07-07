class Solution {
public:
    string source1, source2, target;
    int n , m , all;
    int mem[101][101][201];
    
    int solve(int idx1 , int idx2 , int idx3){
        if(idx3 == all) return 0;
        if(mem[idx1][idx2][idx3] != -1)return mem[idx1][idx2][idx3];
        int path1 = 10000 , path2 = 10000 ;
        if(idx1<n and source1[idx1] == target[idx3]) path1 = 1 + solve(idx1+1, idx2, idx3+1);
        if(idx2<m and source2[idx2] == target[idx3]) path2 = 1 + solve(idx1, idx2+1, idx3+1);
        return mem[idx1][idx2][idx3] = min(path1 , path2);
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size();
        m = s2.size();
        all = s3.size();
        source1 = s1;
        source2 = s2;
        target = s3;
        if(n+m != all)return false;
        memset(mem, -1, sizeof mem);
        return solve(0,0,0) == all;
    }
};