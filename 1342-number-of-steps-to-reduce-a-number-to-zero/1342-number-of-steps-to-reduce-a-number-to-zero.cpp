class Solution {
public:
    int numberOfSteps(int num) {
        int ret = 0;
        while(num){
            ret++;
            if(num&1)num--;
            else num/=2;
        }
        return ret;
    }
};