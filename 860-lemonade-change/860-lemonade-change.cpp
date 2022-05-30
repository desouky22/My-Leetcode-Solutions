class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0 , ten = 0;
        for(int x = 0; x<bills.size(); x++){
            if(bills[x] == 5)five++;
            else if(bills[x] == 10){
                if(five == 0)return false;
                else ten++ , five--;
            }else{
                if(ten>0){
                    ten--;
                    if(five>0)five--;
                    else return false;
                }else{
                    if(five>=3)five-=3;
                    else return false;
                }
            }
        }
        return true;
    }
};