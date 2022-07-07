class Solution {
public:
    int mem[10009];
    int solve(int val){
        if(val == 0)return 0;
        if(mem[val] != -1)return mem[val];
        int path1 = INT_MAX;
        for(int x = 1; x <= val; x ++){
            int square = x*x;
            if(val - square < 0)break;
            path1 = min(path1 , 1 + solve(val - square));
        }
        return mem[val] = path1;
    }
    int numSquares(int number) {
        memset(mem, -1, sizeof mem);
        return solve(number);
    }
};