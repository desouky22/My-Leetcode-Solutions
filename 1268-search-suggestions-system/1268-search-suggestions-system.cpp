class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin() , products.end());
        vector<vector<string>> ret;
        map<string, vector<string>> mp;
        
        for(int x =0; x<products.size(); x++){
            string prefix;
            for(int y = 0; y<products[x].size(); y++){
                prefix+=products[x][y];
                mp[prefix].push_back(products[x]);
            }
        }
        for(auto &it:mp){
            sort(it.second.begin() , it.second.end());
        }
        
        string prefix;
        for(int x = 0; x<searchWord.size(); x++){
            prefix.push_back(searchWord[x]);
            if(mp[prefix].size()<=3)
                ret.push_back(mp[prefix]);
            else{
                vector<string>vv;
                vv = {mp[prefix][0] , mp[prefix][1] , mp[prefix][2]};
                ret.push_back(vv);
            }
        }
        return ret;
    }
};