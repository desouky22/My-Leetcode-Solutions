class Solution {
public:
    map<int,int>mp;
    bool valid(int a , int b){
        return ((mp[a] & mp[b]) == 0);
    }
    
    int maxProduct(vector<string>& words) {
        for(int x = 0; x<words.size(); x++){
            for(auto it: words[x]){
                mp[x] = mp[x] | (1 << (it - 'a'));
            }
        }
        
        long long mx = 0;
        for(int x = 0; x<words.size(); x++){
            for(int y = x+1; y<words.size(); y++){
                if(valid(x, y))
                    mx = max(mx, (long long)words[x].size()*(long long)words[y].size());
            }
        }
        return mx;
    }
};