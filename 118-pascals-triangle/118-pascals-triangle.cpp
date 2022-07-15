class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ret;
        ret.push_back({1});
        if(numRows>1)ret.push_back({1,1});
        for(int x = 2; x<numRows; x++){
            vector<int>ans = {1};
            for(int y = 1; y<ret.back().size(); y++){
                ans.push_back(ret.back()[y-1] + ret.back()[y]);
            }
            ans.push_back(1);
            ret.push_back(ans);
        }
        return ret;
    }
};