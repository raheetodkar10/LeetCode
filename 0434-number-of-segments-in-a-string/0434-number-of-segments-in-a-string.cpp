class Solution {
public:
    int countSegments(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i] != ' ' && (i==0 || s[i-1] == ' ')){  //We use OR (||) because either one is enough to say that s[i] is the beginning of a segment (down)
                cnt++;
            }
        }
        return cnt; 
    }
};
/*
Case 1: i == 0  : If we are at the first character, there is no previous character. So cnt+1
Case 2: s[i-1] == ' '  : If the previous character is a space, then the current character starts a new segment   */