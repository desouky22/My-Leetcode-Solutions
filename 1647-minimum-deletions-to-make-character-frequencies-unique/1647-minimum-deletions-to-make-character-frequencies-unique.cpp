class Solution {
public:
    
int minDeletions(string s) {
    map<char, int>mp;
    for(auto it: s)mp[it] ++;
    map<int , int>freq;
    int maxFreq = 0;
    for(auto it: mp) {freq[mp[it.first]] ++; maxFreq = max(maxFreq, mp[it.first]);}
    vector<int>allValid;
    for(int x = 1; x<=maxFreq; x++){
        if(freq[x] == 0)allValid.push_back(x);
    }

    cout<<"\n";
    for(auto it : allValid)cout<<it<<"\n";
    int ret = 0;
    for(auto it = freq.rbegin(); it!=freq.rend(); it ++){
        while(it->second > 1){
            if(allValid.size() == 0) ret += it->first;
            else{
                if(allValid.back() > it->first) { allValid.pop_back();continue; }
                ret += it->first - allValid.back() ;
                allValid.pop_back();
            }
            it->second --;
        }
    }
    return ret;
}


};