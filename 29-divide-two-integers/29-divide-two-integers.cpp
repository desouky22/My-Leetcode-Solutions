typedef long long ll;
class Solution {
public:
    bool valid(ll mid, ll divisor, ll dividend){
        return (mid * divisor) <= dividend;
    }
    
    ll getPosNum(ll divisor, ll dividend){
        ll left = 0LL, right = 2147483649;
        while(right-left!=1){
            ll mid = (left + right) / 2;
            if(valid(mid, divisor, dividend)) left = mid;
            else right = mid;
        }
        return left;
    }
    
    int divide(ll dividend, ll divisor) {
        if(dividend == 0)return 0;
        int neg = 0;
        if(divisor < 0)neg++;
        if(dividend < 0) neg++;
        if(neg%2==0){
            ll ret = getPosNum(abs(divisor), abs(dividend));
            cout<<ret<<"\n";
            if(ret > (2147483647LL)) ret = 2147483647LL;
            return ret;
        }
        else{
            ll ret = -getPosNum(abs(divisor), abs(dividend));
            if(ret<(-2147483648LL)) ret = -2147483648LL;
            return ret;
        }
    }
};