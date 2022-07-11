class Solution {
public:
    int n , fee;
    vector<int>v;
    int mem[50009][2];
    int solve(int index = 0, bool buy = true){
        if(index == n)return 0;
        if(mem[index][buy] != -1)return mem[index][buy];
        int path1 = 0 , path2 = 0;
        if(buy){
            path1 = -v[index] + solve(index+1, false);
            path2 = solve(index+1, buy);
            return mem[index][buy] = max(path1 , path2);
        }else{
            path1 = v[index] + solve(index+1, true) - fee;
            path2 = solve(index+1, buy);
            return mem[index][buy] = max(path1 , path2);
        }
    }
    
    int maxProfit(vector<int>& prices, int f) {
        v = prices;
        n = v.size();
        fee = f;
        memset(mem, -1, sizeof mem);
        return solve();
    }
};