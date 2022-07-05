class Solution {
public:
    int n;
    vector<int>v;
    int mem[200][2];
    int solve(int index, bool firstOne){
        if(index >= n)return 0;
        if(mem[index][firstOne]!=-1)return mem[index][firstOne];
        if(index == 0){
            int path1 = v[index] + solve(index+2, true);
            int path2 = solve(index+1, false);
            return mem[index][firstOne] = max(path1 , path2);
        }else if(index == n-1){
            int path1 = 0;
            if(!firstOne) path1 = v[index] + solve(index+2, firstOne);
            int path2 = solve(index+1, firstOne);
            return mem[index][firstOne] = max(path1 , path2);
        }
        
        int path1 = v[index] + solve(index+2, firstOne);
        int path2 = solve(index+1, firstOne);
        return mem[index][firstOne] = max(path1 , path2);

    }
    int rob(vector<int>& nums) {
        v = nums;
        n = v.size();
        memset(mem, -1, sizeof mem);
        return solve(0,0);
    }
};