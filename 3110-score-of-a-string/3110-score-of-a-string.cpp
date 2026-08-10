class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;
        for(int i=0;i<s.size()-1;i++){
            sum += abs(s[i+1]-s[i]);    //char is automatically converted to its integer value when we perform arithmetic on it
        }
        return sum;
    }
};