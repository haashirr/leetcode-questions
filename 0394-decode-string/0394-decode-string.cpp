class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        stack<int>count;
        int k=0;
        string str="";
        for(auto i:s) {
            if(isdigit(i)) {
                k=k*10+i-'0';
            }
            else if(i=='[') {
                count.push(k);
                k=0;
               st.push(str);
                str="";
            }
            else if(i==']') {
                int c = count.top();
                count.pop();
                string x = st.top();
                st.pop();
                for(int j=0;j<c;j++) {
                    x+=str;
                }
                str=x;
            }
            else {
                str+=i;
            }
        }
        return str;
    }
};