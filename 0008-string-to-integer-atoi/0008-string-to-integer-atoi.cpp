class Solution {
public:
    int myAtoi(string s) {
        int i=0, n = s.size()-1;
        while(s[i]==' ') { //skipping whitespaces at the beginning
            i++;
        }
        int positive=0, negative=0;
        if(s[i]=='+') { //number of positive signs 
            positive++;
            i++;
        }
        if(s[i]=='-') { //number of negative signs
            negative++;
            i++;
        }
        double ans=0;
        while(i<=n && s[i]>='0' && s[i]<='9') {
            ans = ans*10 + (s[i]-'0'); //(s[i]-'0') converts character to integer
            i++;
        }
        if(negative>0) { //if negative exists
            ans = -ans;
        }
        if(positive>0 && negative>0) { //if both +ve and -ve are present. for eg -> +-12
            return 0;
        }
        if(ans>INT_MAX) { //if ans > 2^31-1
            ans = INT_MAX;
        }
        if(ans<INT_MIN) {
            ans = INT_MIN; //if ans < 2^31;
        }
        return (int)ans;
    }
};