class Solution {
public:
    int getProduct(int n){
        int ret = 1;
        while(n){
            ret *= n % 10;
            n /= 10;    
        }
        return ret;
    }
    
    int getSum(int n){
        int ret = 0;
        while(n){
            ret += n%10;
            n/=10;
        }
        return ret;
    }
    
    int subtractProductAndSum(int n) {
        return getProduct(n) - getSum(n);
    }
};