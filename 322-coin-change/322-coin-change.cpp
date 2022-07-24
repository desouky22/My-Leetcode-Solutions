class Solution {
public:
    typedef long long ll;
    ll n , target;
    vector<int>coins;
    ll mem[20][10009];
    ll solve(int index, int rem){
        if(rem == 0)return 0;
        if(rem < 0)return ll(INT_MAX);
        if(index == n)return ll(INT_MAX);
        if(mem[index][rem] != -1)return mem[index][rem];
        ll path1 = 1 + solve(index, rem - coins[index]);
        ll path2 = solve(index+1, rem);
        return mem[index][rem] = min(path1 , path2);
    }
    int coinChange(vector<int>& c, int amount) {
        coins = c;
        target = amount;
        n = c.size();
        memset(mem, -1, sizeof mem);
        if(solve(0, target) >= INT_MAX)return -1;
        else return solve(0, target);
    }
};