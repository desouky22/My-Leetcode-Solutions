class Solution {
public:
    string s1 , s2;
    int n ,m;
    int dp[600][600];
    int LCS(int i, int j){
        if(i == n or j == m) return 0;
        int &ret = dp[i][j];
        if(~ret)return ret;
        ret = 0;
        if(s1[i] == s2[j])
            return ret =  1+LCS(i+1 , j+1);
        else
            return ret = max(LCS(i+1,j) , LCS(i,j+1));
    }
    
    int minDistance(string word1, string word2) {
        s1 = word1 , s2 = word2;
        n = word1.size() , m = word2.size();
        memset(dp, -1, sizeof dp);
        cout<<LCS(0,0);
        return n+m - 2*LCS(0,0);
    }
};