class Solution {
public:
    string s;
    int mem[1009][1009];
    int solve(int idx1 , int idx2){
        if(idx1 >= idx2) return 1;
        if(mem[idx1][idx2] != -1)return mem[idx1][idx2];
        if(s[idx1] == s[idx2]) return mem[idx1][idx2] = solve(idx1+1, idx2-1);
        return mem[idx1][idx2] = 0;
    }
    
    string longestPalindrome(string str) {
        memset(mem, -1, sizeof mem);
        s = str;
        solve(0, s.size()-1);
        string ans;
        ans+=s[0];
        int bestVal = 1;
        for(int x = 0; x<s.size(); x++){
            for(int y = x+1; y<s.size(); y++){
                if(solve(x,y) != 0 and bestVal < (y-x+1)){
                    bestVal = y-x+1;
                    ans = "";
                    for(int z = x; z<=y; z++)ans+=s[z];
                }
            }
        }
        return ans;
    }
};