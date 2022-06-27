class Solution {
public:
    int minPartitions(string n) {
        int ret = 0;
        for(int x = 0; x<n.size(); x++){
            int digit = n[x]-'0';
            ret = max(ret, digit);
        }
        return ret;
        
    }
};