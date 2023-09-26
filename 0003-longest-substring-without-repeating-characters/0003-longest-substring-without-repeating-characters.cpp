class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int maxCount=0;
       unordered_set<char>st;
        int left=0;
        for(int i=0;i<s.size();i++) {
            if(st.count(s[i])==0) {
                st.insert(s[i]);
                maxCount = max(maxCount,i-left+1);
            }
            else {
                while(st.count(s[i])) {
                    st.erase(s[left]);
                    left++;
                }
                st.insert(s[i]);
            }
        }
        return maxCount;
    }
};