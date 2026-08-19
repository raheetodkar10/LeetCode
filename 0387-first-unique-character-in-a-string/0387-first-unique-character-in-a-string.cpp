class Solution {
public:
    int firstUniqChar(string s) {

        map<char,int> freq;
        //count freq
        for(char ch:s){
            freq[ch]++;
        }
        // Find first character with frequency 1
        for(int i=0;i<s.size();i++){
            if(freq[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};