class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        int oddCount=0;
        for(auto c:s) {
            mp[c]++;
            if(mp[c]%2==0) {
                oddCount--;
            }
            else {
                oddCount++;
            }
        }
        if(oddCount>1) {
            return s.length()-oddCount+1;
        }
        return s.length();
    }
};