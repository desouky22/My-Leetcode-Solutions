class Solution {
typedef long long ll;
int dp[2000][2000];
public:
    ll solve(ll i,ll j,string &s,string &t){
        if(j == -1)return 1;
        if(i == -1)return 0;
        int &ret=dp[i][j];
        if(ret!=-1)return ret;
        int option1,option2;
        if(s[i]==t[j]){
            option1=solve(i-1,j-1,s,t);
            option2=solve(i-1,j,s,t);
            return ret=option1+option2;
        }
        return ret=solve(i-1,j,s,t);
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof dp);
        return solve(s.size(),t.size(),s,t);
    }
};