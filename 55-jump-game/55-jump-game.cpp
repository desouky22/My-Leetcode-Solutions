class Solution {
public:
    int n;
    vector<int>v;
    int mem[10009];
    int solve(int index){
        if(index >= n-1)return 1;
        if(v[index] == 0)return 0;
        if(mem[index] != -1)return mem[index];
        int path1 = 0;
        for(int x = 1; x<=min(v[index] , (n-1)-index); x++){
            path1 = max(path1 , solve(index+x));
            if(path1 != 0)break;
        }
        return mem[index] = path1;
    }
    
    bool canJump(vector<int>& nums) {
        n = nums.size();
        v = nums;
        memset(mem, -1, sizeof mem);
        return solve(0)!=0;
    }
};