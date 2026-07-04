class Solution {
public:
    int maxPower(string s) {
        int count=1; //single character itself has power 1 so jari ab asel tari power of a = power of b = 1 asnar
        int maxi=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                count++;
            }
            else{
                count=1;  //new streak starts
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};