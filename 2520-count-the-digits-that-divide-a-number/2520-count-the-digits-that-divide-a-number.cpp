class Solution {
public:
    int countDigits(int num) {
        int cnt=0;
        int og=num;
        while(num>0){
            int dig = num % 10;
            //num = num/10;
            if(og % dig == 0){
                cnt++;
            }
            num = num/10;
        }
        /*if(dig % num == 0){
            cnt++;
        }*/
        return cnt;
        
    }
};