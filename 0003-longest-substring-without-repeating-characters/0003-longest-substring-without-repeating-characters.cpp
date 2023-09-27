class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int maxCount=0;
      vector<int>v(128,-1);
        int left=0;
        for(int i=0;i<s.size();i++) {
            if(v[s[i]]>=left) {
                left = v[s[i]]+1;
            }
            v[s[i]]=i;
            maxCount = max(maxCount,i-left+1);
        
        }
        return maxCount;
    }
};