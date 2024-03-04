class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>vis(wordList.begin(),wordList.end());
        vis.erase(beginWord);

        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) {
                return steps;
            }
            for(int i=0;i<word.size();i++) {
                int original = word[i];
                for(char c='a';c<='z';c++) {
                    word[i] = c;
                    if(vis.find(word)!=vis.end()) {
                        vis.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};