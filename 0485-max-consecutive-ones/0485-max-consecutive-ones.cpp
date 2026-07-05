class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++; //If element is 1, count++ and continue streak
            }
            else{
                count=0;  //If element is 0, count = 0 because streak breaks
            }
            maxi=max(maxi,count); //stores largest streak
        }
        return maxi;
    }
};