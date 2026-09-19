class Solution {
public:
    bool isBalanced(string num) {
        int even=0, odd=0;
        //int sum=0;
        for(int i=0;i<num.size();i++){
            if(i%2==0){
                even += num[i]-'0';  //fakt num[i] lihila tr it will add the ascii values (not the elem on that index), so -'0'
            }
            else{
                odd += num[i]-'0';
            }
        }
        if(even==odd){
            return true;
        }
        /*else{
            return false;
        }*/
        return false; 
    }
};