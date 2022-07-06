class Solution {
public:
    typedef long long ll;
    int all;
    vector<int>v;
    int n;
    int mem[25][25];
    ll solve(int left, int right, bool player1 = true){
        if(right < left) return 0;
        if(mem[left][right] != -1)return mem[left][right];
        ll path1 = 0 , path2 = 0;
        if(player1){
            // player 1
            path1 = v[left] + solve(left+1, right, !player1);
            path2 = v[right] + solve(left, right-1, !player1);
            return mem[left][right] = max(path1 , path2);
        }else{
            path1 = solve(left+1 , right, !player1);
            path2 = solve(left, right-1, !player1);
            return mem[left][right] = min(path1 , path2);
        }
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        for(auto it: nums) all += it;
        v = nums;
        n = v.size();
        memset(mem, -1, sizeof mem);
        ll playerOne = solve(0,n-1);
        ll playerTwo = all-playerOne;
        return playerOne >= playerTwo;
    }
};