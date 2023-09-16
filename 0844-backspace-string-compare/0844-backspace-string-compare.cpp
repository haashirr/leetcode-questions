class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1;
        stack<char>st2;
        for(auto i:s) {
            if(i!='#') {
                st1.push(i);
            }
            else {
                if(!st1.empty()) {
                    st1.pop();
                }
              
            }
        }
        for(auto i:t) {
            if(i!='#') {
                st2.push(i);
            }
            else {
                if(!st2.empty()) {
                    st2.pop();
                }
              
            }
        }
        return st1==st2;
    }
};