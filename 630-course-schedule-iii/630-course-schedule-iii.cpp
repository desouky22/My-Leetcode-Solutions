class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin() , courses.end() , [](vector<int>&a, vector<int>&b) {
            if(a[1] < b[1])return true;
            else if(a[1] == b[1]) return a[0] < b[0];
            return false;
        });
        int ret = 0;
        int days = 0;
        int idx = 0;
        priority_queue<int>pq;
        while(idx < courses.size()){
            if(courses[idx][0] + days <= courses[idx][1]) {
                ret ++;
                days += courses[idx][0];
                pq.push(courses[idx][0]);
            }else{
                cout<<"days: "<<days<<"\n";
                if(pq.size()){
                    int biggestDay = pq.top();
                    if(biggestDay <= courses[idx][0]){
                        idx++;
                        continue;
                    }                
                
                    pq.pop();
                    days -= biggestDay;
                    ret --;
                    cout<<biggestDay<<" "<<courses[idx][0]<<" "<<courses[idx][1]<<"\n";
                    if(courses[idx][0] + days <= courses[idx][1]) {
                        ret ++;
                        days += courses[idx][0];
                        pq.push(courses[idx][0]);
                        cout<<"yeah "<<biggestDay<<" "<<courses[idx][0]<<" "<<courses[idx][1]<<"  "<<days<<"\n";

                    }else{
                        pq.push(biggestDay);
                        days += biggestDay;
                        ret ++;
                    }
                }
            }
            idx ++;
        }
        return ret;
    }
};