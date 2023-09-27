
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int>freq,mp;
        for(auto ele:p){
            freq[ele]++;
        }
        int n=s.size(),m=p.size();
        for(int i=0;i<m;i++){
            mp[s[i]]++;
        }
        int r=m-1;
        bool ok=1;
        for(char c='a';c<='z';c++){
            if(mp[c]!=freq[c]){
                ok=0;
                break;
            }
        }
        vector<int> ans;
        if(ok){
            ans.push_back(0);
        }
        int l=0;
        l++;
        r++;
        while(r<n){
            mp[s[l-1]]--;
            mp[s[r]]++;
            bool ok=1;
            for(char c='a';c<='z';c++){
                if(mp[c]!=freq[c]){
                    ok=0;
                    break;
                }
            }
            if(ok){
                ans.push_back(l);
            }
            l++;
            r++;
        }
        return ans;
    }
};
