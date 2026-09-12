class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> st;  //unique elem, so used set instead of cnt
        for(int i=0;i<digits.size();i++){
            for(int j=0;j<digits.size();j++){
                for(int k=0;k<digits.size();k++){
                    // cannot use the same digit position twice
                    if(i==j || j==k || k==i){
                        continue;
                    }
                    //first dig can't be 0
                    if(digits[i]==0){
                        continue;
                    }
                    // last digit must be even
                    if(digits[k] % 2 == 0){
                        int num = digits[i] * 100 + digits[j] * 10 + digits[k] * 1;
                        st.insert(num);
                    }
                }
            }
        }
        return st.size();
    }
};
/* For example, suppose:
digits[i] = 1 , digits[j] = 2 , digits[k] = 4;
We want to make: 124
Mathematically: 
1 × 100 = 100
2 × 10  =  20
4 × 1   =   4
equals:   124
Therefore: int num = digits[i] * 100 + digits[j] * 10 + digits[k];   */