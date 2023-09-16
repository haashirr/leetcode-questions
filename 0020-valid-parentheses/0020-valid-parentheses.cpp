class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char i:s) {
            if(st.empty() || i=='(' || i=='[' || i=='{') {
                st.push(i);
            }
            if(i==')') {
                if(st.top()=='(') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else if(i==']') {
                if(st.top()=='[') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else if(i=='}') {
                if(st.top()=='{') {
                   st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};