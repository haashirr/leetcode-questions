class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>result;
        stack<int>st;
        for(auto i:asteroids) {
            if(i>0) {
                st.push(i);
            }
            else {
                while(!st.empty() && st.top()>0 && abs(i)>st.top()) {
                    st.pop();
                }
                if(st.empty() || st.top()<0) {
                    st.push(i);
                }
                else if(abs(st.top())==abs(i)) {
                    st.pop();
                }
            }
        }
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};