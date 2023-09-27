class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lens = s.length();
        int lenp = p.length();
        vector<int>ans;
        if(lenp>lens) {
            return {};
        }
        unordered_map<char,int>pattern_freq;
        unordered_map<char,int>window;
        for(auto c:p) {
            pattern_freq[c]++;
        }
        for(int i=0;i<lenp;i++) {
            window[s[i]]++;
        }
        if(pattern_freq==window) {
            ans.push_back(0);
        }
        for(int i=lenp;i<lens;i++) {
            char left_char = s[i-lenp];
            if(window[left_char]==1) {
                window.erase(left_char);
            }
            else {
                window[left_char]--;
            }
            char new_char = s[i];
            window[new_char]++;
            if(pattern_freq==window) {
                ans.push_back(i-lenp+1);
            }
        }
        return ans;
    }
};