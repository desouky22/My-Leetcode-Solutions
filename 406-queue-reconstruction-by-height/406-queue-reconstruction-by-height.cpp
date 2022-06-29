class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<pair<pair<int , int>, pair<int , int>>>v;
        map<pair<int ,int>, bool>done;
        sort(people.begin() , people.end(),[](vector<int>&a , vector<int>&b){
            if(a[0] < b[0])return true;
            else if(a[0] == b[0]){
                if(a[1] < b[1])return true;
                else return false;
            }else
                return false;
        });
        for(auto it: people) v.push_back({{it[0],it[1]}, {it[0] , it[1]}});
        vector<vector<int>> ret;
        for(int x = 0; x<people.size(); x++){
            pair<int , int> cur = {INT_MAX , 0} , valid = {INT_MAX , 0};
            for(auto &it: v){
                if(it.first.second == 0 and !done[it.second]){
                    if(it.first.first < cur.first){
                        cur = it.first;
                        valid = it.second;
                    }
                }
            }
            done[valid] = true;
            ret.push_back({valid.first, valid.second});
            for(auto &it: v){
                if(valid.first >= it.first.first and !done[it.second]){
                    it.first.second--;
                }
            }
        }
        
        
        
        
        
        return ret;
    }
};