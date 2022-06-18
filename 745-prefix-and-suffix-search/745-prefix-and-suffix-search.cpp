class WordFilter {
public:
    unordered_map<string , int> ans;
    unordered_map<string, bool> exist;

    WordFilter(vector<string>& words) {
        for(int x = 0; x<words.size(); x++){
            string pref;
            for(int y = 0; y<words[x].size(); y++){
                pref+=words[x][y];
                for(int z = words[x].size()-1; z>=0; z--){
                    string suf = words[x].substr(z);
                    string str = pref + '#' + suf;
                    ans[str] = x;
                    exist[str] = true;
                }
            }
        }
        
    }
    
    int f(string prefix, string suffix) {
        if(exist[prefix+'#'+suffix])return ans[prefix+'#'+suffix];
        return -1;
        
    }
};