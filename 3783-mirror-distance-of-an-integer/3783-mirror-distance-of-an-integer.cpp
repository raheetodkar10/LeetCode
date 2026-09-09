class Solution {
public:
    int reverse(int n){
        int ans = 0;
        while(n!=0){
            int digit = n%10;
            ans = ans*10 + digit;
            n=n/10;
        }
        return ans;
    }
    int mirrorDistance(int n) {
        reverse(n);
        return abs(n-reverse(n)); 
    }
};