class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int maxCount=0;
       unordered_map<char,int>st;
        int left=0;
        for(int i=0;i<s.size();i++) {
            if(st.count(s[i])==0 || st[s[i]]<left) {
                st[s[i]]=i;
                maxCount = max(maxCount,i-left+1);
            }
            else {
                left = st[s[i]]+1;
                st[s[i]]=i;
            }
        }
        return maxCount;
    }
};