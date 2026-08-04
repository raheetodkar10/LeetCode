class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int oddCnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i] % 2 != 0){
                oddCnt++;
            }
            else{
                oddCnt=0;
            }
            if(oddCnt==3){
                return true;
            }
            // else{
            //     return false;
            // }
        }
        return false;
    }
};