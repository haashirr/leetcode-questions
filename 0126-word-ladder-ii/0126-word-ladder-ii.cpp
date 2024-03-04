class Solution {
    vector<vector<string>>ans;
    unordered_map<string, int>mp;
    void dfs(vector<string>v, string beginWord) {
        string lastWord = v[v.size()-1];
        if(lastWord == beginWord) {
            reverse(v.begin(), v.end());
            ans.push_back(v);
            return;
        }
        int level = mp[lastWord];
        for(int i=0;i<lastWord.size();i++) {
            char original = lastWord[i];
            for(char c='a';c<='z';c++) {
                lastWord[i] = c;
                if(mp.count(lastWord) && mp[lastWord]+1 ==level) {
                    v.push_back(lastWord);
                    dfs(v, beginWord);
                    v.pop_back();
                }
            }
            lastWord[i] = original;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
       // mp.clear();
       // ans.clear();
        unordered_set<string>s(wordList.begin(), wordList.end());
        queue<string>q;
        q.push(beginWord);
        if(s.find(beginWord)!=s.end()) {
            s.erase(beginWord);
        }
        if(s.find(endWord)==s.end()) {
            return {};
        }
        int dist = 0;
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                string word = q.front();
                q.pop();
                mp[word] = dist;
                if(word==endWord) {
                    goto label;
                }
                for(int i=0;i<word.size();i++) {
                    char original = word[i];
                    for(char c='a';c<='z';c++) {
                        word[i] = c;
                        if(s.find(word)!=s.end()) {
                            s.erase(word);
                            q.push(word);
                        }
                    }
                    word[i] = original;
                }
            }
            dist++;
        }
        label:
        vector<string>v = {endWord};
        dfs(v, beginWord);
        return ans;

    }
};