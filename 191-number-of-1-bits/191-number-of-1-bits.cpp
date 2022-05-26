class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while(n){
            if(n%2 == 1)ret++;
            n/=2;
        }
        return ret;
    }
};

// 101