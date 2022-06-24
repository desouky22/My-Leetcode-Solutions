class Solution {
public:
    bool isPossible(vector<int>& target) {
        sort(target.begin() , target.end());
        if(target.size() == 1){
            return target[0] == 1;
        }
        int n = target.size();
        priority_queue<int>pq;
        for(auto it: target)pq.push(it);
        long long sum = 0;
        for(auto it : target)sum += it;
        while(pq.top() != 1){
            int biggestVal = pq.top(); pq.pop();
            sum -= biggestVal;
            if(sum == 1)return true;
            if(sum > biggestVal or sum == 0)return false;
            if(biggestVal % sum == 0)return false;
            pq.push(biggestVal % sum);
            sum += biggestVal % sum;
        }
        return true;
    }
};