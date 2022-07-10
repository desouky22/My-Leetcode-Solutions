class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0 , end = 0;
        int ans = 0;
        int n = s.size();
        map<char, int>mp;
        while(end < n){
            ans = max(ans, end-start);
            if(mp[s[end]] == 0){
                mp[s[end]] ++;
                end++;
            }else{
                mp[s[start]] --;
                start ++;
            }
        }
        ans = max(ans, end-start);

        return ans;
        
    }
};