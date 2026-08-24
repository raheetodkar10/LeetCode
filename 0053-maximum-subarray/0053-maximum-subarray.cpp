class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Kadane's Algorithm
        int maxi=INT_MIN;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
        }
        return maxi;
    }
};

/*Suppose current sum becomes negative  :  sum = -5
Now the next number is 10
Option 1: Continue with old sum : -5 + 10 = 5
Option 2: Start a new subarray : 10
better is : start a new as 10 > 5(max)
So carrying a negative sum only hurts future sums
mhanje jr sum negative asel tr navin elem pasun sum start kelela changla
*/