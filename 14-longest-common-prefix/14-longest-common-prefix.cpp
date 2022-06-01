class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        map<string, int> mp;
        for(int x = 0; x<strs.size(); x++){
            string tmp;
            mp[tmp]++;
            for(int y = 0; y<strs[x].size(); y++){
                tmp+=strs[x][y];
                mp[tmp]++;
            }
        }
        string ans;
        for(auto it: mp){
            if(it.second == strs.size()){
                if(ans.size() < it.first.size())ans = it.first;
            }
        }
        return ans;
    }
};