class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>st;
        for(auto it: nums)st.insert(it);
        return st.size() != nums.size();
    }
};