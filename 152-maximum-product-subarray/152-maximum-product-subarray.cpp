class Solution {
public:
int n;
vector<int>v;
map<int , map <int , int> >mem;
int solve(int index ,int ans){
    if(index == n)return ans;
    int &ret =mem[index][ans];
    if(ret != 0)return ret;
    int path1 = solve(index+1 , ans * v[index]);
    int path2 = max(ans, solve(index+1 , v[index]));
    return ret = max(path1 , path2);
}

int maxProduct(vector<int>& nums) {
    if(nums.size()==1)return nums[0];
    n = nums.size();
    v = nums;
    int ret = solve(0,0);
    return ret;
}
};