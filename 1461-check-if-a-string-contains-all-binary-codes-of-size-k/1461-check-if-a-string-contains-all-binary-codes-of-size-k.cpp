class Solution {
public:
    int toInt(deque<char>&dq){
        int ret = 0;
        int index = 1;
        for(auto &it: dq){
            ret += (it=='1')*index;
            index *= 2;
        }
        return ret;
    }
    
    bool hasAllCodes(string s, int k) {
        if(k>s.size())return false;
        set<int>st;
        deque<char>dq;
        for(int x = 0; x<k; x++) dq.push_back(s[x]);
        int l = 0 , r = k-1;
        st.insert(toInt(dq));
        while(r<s.size()-1){
            dq.pop_front();
            l++;
            r++;
            dq.push_back(s[r]);
            
            st.insert(toInt(dq));
        }
        return st.size() == pow(2,k);
    }
};