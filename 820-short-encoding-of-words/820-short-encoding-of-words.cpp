class Solution {
public:
    map<string, bool>mp;
    int minimumLengthEncoding(vector<string>& words) {
        string ans;
        sort(words.begin() , words.end(), [](string &a, string &b){return a.size()>b.size();});
        for(auto it: words){   
            cout<<it<<"\n";
            if(mp[it])continue;
            string temp = it;
            string suffix;
            for(int x = temp.size()-1; x>=0; x--){
                suffix = temp[x] + suffix;
                mp[suffix] = true;
                cout<<suffix<<"\n";
            }
            ans += it;
            ans +='#';
        }
        cout<<ans;
        return ans.size();
    }
};