class Solution {
public:
    bool checkDivisibility(int n) {
        int og=n;   //jr og nai create kela tr to while loop mde destroy hotoy ie we get n=0 at end. So original n value og mde store karaychi so that we can check it with if-else
        int digSum=0;
        int digProd=1;
        while(n!=0){
            int dig = n % 10;
            digSum += dig;
            digProd *= dig;
            n = n / 10;
        }
        int finalAns = digSum + digProd;
        if(og % finalAns == 0) return true;
        return false;
    }
};