class Solution {
public:
    bool isPal(string s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        //Two pointers
        int left = 0;
        int right = s.size()-1;
        while(left < right){
            if(s[left] == s[right]){
                left++;
                right--;
            }
            else{
                //2 possibilities: ek tr left pudhe gheun delete kru shakto naitr right mage gheun delete kru shakto. If either of this is true we'll return true
                return isPal(s, left+1, right) || isPal(s, left, right-1);
            }
        }
        return true;  //ethe alo tr we'll get case like:aba which is palindrome
    }
};