class Solution {
public:
    bool isVowel(char c){
        return string("aeiou").find(c) != string::npos;  //Check whether character c exists in the string "aeiou". If found → true, If not found → false    
    }
    /*1.string("aeiou"): creates a temporary string containing all five vowels
    2. .find(c): The find() function searches for character c inside the string.
    - If the character is found, it returns its index (position).
    - If the character is not found, it returns string::npos.
    3. string::npos: npos means not found.  */

    int maxVowels(string s, int k) {   //TC:O(N), SC:O(1)
        //Fixed size sliding window
        int count = 0, maxi = 0;
        //count vowels in first window
        for(int i=0;i<k;i++){
            if(isVowel(s[i])) count++;
        }

        maxi = count;
        //slide the window
        for(int i=k;i<s.size();i++){
            if(isVowel(s[i-k])) count--;  //outgoing character, remove its vowel count
            if(isVowel(s[i])) count++;  //incoming character, add its vowel count
            maxi = max(maxi, count);
        }
        return maxi;
    }
};