/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
typedef long long ll;
class Solution {
public:
    int guessNumber(int n) {
        ll left = 0, right = 2147483648;
        while(right-left != 1){
            ll mid = (left + right) / 2;
            if(guess(mid) == -1)right = mid;
            else if(guess(mid) == 1)left = mid;
            else {
                return mid;
            }
        }
        return 0;
    }
};