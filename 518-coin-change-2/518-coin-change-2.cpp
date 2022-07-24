class Solution {
public:
    typedef long long ll;
    ll target, n;
    vector<int>coins;
    ll mem[309][5009];
    ll solve(int index, int rem){
        if(rem == 0)return 1;
        if(rem < 0)return 0;
        if(index == n)return 0;
        if(mem[index][rem] != -1)return mem[index][rem];
        ll path1 = solve(index, rem - coins[index]);
        ll path2 = solve(index+1, rem);
        return mem[index][rem] = path1 + path2;
    }
    int change(int amount, vector<int>& c) {
        target = amount;
        n = c.size();
        coins = c;
        memset(mem, -1, sizeof mem);
        return solve(0, target);
    }
};