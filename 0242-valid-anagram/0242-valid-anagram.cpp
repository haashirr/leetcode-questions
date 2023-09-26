class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(auto c:s) {
            mp[c]++;
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