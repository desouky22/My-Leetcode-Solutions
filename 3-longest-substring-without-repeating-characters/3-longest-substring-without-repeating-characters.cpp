class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if(s.empty())return 0;
        int ret = 0 , ans = 0;
        int l  = 0 , r = 0;
        map<char , int>mp;
        while(r != s.size()){
            if(mp[s[r]] == 0){
                mp[s[r]]++;
                r++;
                ret++;
                ans = max(ret,ans);
            } else{
                mp[s[l]]--;
                l++;
                ret--;
            }          
            ans = max(ret,ans);
        }
        return ans;
    }
};