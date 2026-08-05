class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int Esum=0, Dsum=0;
        for(int i=0;i<nums.size();i++){
            Esum += nums[i];
            int temp = nums[i];
            while(temp>0){
                Dsum += temp % 10;
                temp /= 10;
            }
        }
        return abs(Esum-Dsum);
    }
};