class Solution {
public:
string str;
string go(int x){
    string temp1 , temp2;
    int l = x - 1 , r = x + 1;
    while(l >= 0 and r < str.size()){
        if(str[l] == str[r]) l-- , r++;
        else break;
    }
    l++ , r--;

    for(int x = l; x<=r; x++){
        if(x>=0 and x < str.size())
            temp1.push_back(str[x]);
    }

    l = x , r = x+1;
    while(l >= 0 and r < str.size()){
        if(str[l] == str[r]) l-- , r++;
        else break;
    }
    l++ , r--;
    for(int x = l; x<=r; x++){
        if(x>=0 and x < str.size())
            temp2.push_back(str[x]);
    }
    cout<<temp1<<" "<<temp2<<"\n";

    return (temp1.size() > temp2.size()) ? temp1 : temp2;
}

string longestPalindrome(string s) {
    str = s; string ret;
    ret+=s[0];
    cout<<ret<<"\n";
    for(int x = 0; x<s.size(); x++){
        string subStr = go(x);
        if(subStr.size() > ret.size()) ret = subStr;
    }
    return ret;
}
};