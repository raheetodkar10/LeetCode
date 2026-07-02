class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0){
            return false;
        } 
        for(int x=0;x<=30;x++){
            if(n==pow(3,x)){
                return true;
            }
        } 
        return false;  
    }
};