class Solution {
public:
    int n;
    vector<int>v;
    int mem[1500];
    int solve(int index){
        if(index >= n)return 0;
        if(mem[index] != -1)return mem[index];
        int path1 = 0 , path2 = 0;
        path1 = v[index] + solve(index + 1);
        path2 = v[index] + solve(index + 2);
        return mem[index] = min(path1 , path2);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        memset(mem, -1, sizeof mem);
        n = cost.size();
        v = cost;
        int path1 = solve(0);
        memset(mem, -1, sizeof mem);
        int path2 = solve(1);
        return min(path1,path2);
    }
};