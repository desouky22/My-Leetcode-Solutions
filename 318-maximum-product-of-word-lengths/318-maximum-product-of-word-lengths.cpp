class Solution {
public:
    map<string,int>mp;
    bool valid(string a , string b){
        return ((mp[a] & mp[b]) == 0);
    }
    
    int maxProduct(vector<string>& words) {
        for(int x = 0; x<words.size(); x++){
            for(auto it: words[x]){
                mp[words[x]] = mp[words[x]] | (1 << (it - 'a'));
            }
        }
        
        long long mx = 0;
        for(int x = 0; x<words.size()-1; x++){
            for(int y = x+1; y<words.size(); y++){
                if(valid(words[x], words[y]))
                    mx = max(mx, (long long)words[x].size()*(long long)words[y].size());
            }
        }
        return mx;
    }
};