class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(auto c:s) {
            if(mp.find(c)!=mp.end()) {
                mp[c]++;
            }
            else {
                mp[c]=1;
            }
        }
        for(auto i:t) {
            if(mp.find(i)!=mp.end()) {
                mp[i]--;
            }
            else {
                mp[i]++;
            }
        }
        for(auto x:mp) {
            if(x.second!=0) {
                return false;
            }
        }
        return true;
    }
};