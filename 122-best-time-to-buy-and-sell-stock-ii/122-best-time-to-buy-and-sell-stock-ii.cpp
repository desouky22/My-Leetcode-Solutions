class Solution {
public:
    int n ;
    vector<int>v;
    int mem[30009][2][2];
    int solve(int index = 0, bool buy = false, bool sell= false){
        if(index == n)return 0;
        if(mem[index][buy][sell] != -1)return mem[index][buy][sell];
        int path1 = 0 , path2 = 0 , path3 = 0 , path4 = 0;
        if(!buy) path1 = -v[index] + solve(index+1, true, sell);
        if(buy and !sell) path2 = v[index] + solve(index+1, buy, true);
        if(buy and sell) path3 = solve(index, false, false);
        path4 = solve(index+1, buy, sell);
        return mem[index][buy][sell] = max({path1 , path2 ,path3 , path4});
    }
    int maxProfit(vector<int>& prices) {
        v = prices;
        n = v.size();
        memset(mem, -1, sizeof mem);
        return solve();
    }
};